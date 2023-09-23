#include "monty.h"
#include <stdio.h>
access_d *data_lib;
void opc_sorter(char *arg);
/**
 * main - program entry point
 * @ac: argument count
 * @av: array of string arguments
 * Return: 0 always
 */
int main(int ac, char **av)
{
	char *linetok, *opc, *arg, *arg2, buf[1024];
	FILE *file;
	unsigned int ln = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}


	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	data_lib = malloc(sizeof(access_d));
	data_lib->stack = &stack;
	data_lib->file = file;
	if (data_lib == NULL)
		exit(EXIT_FAILURE);
	data_lib->queue = 0;

	while (fgets(buf, sizeof(buf), file))
	{
		ln++;
		linetok = strtok(buf, "\n");
		data_lib->history = 0;
		opc = strtok(linetok, " ");
		if (opc && opc[0] == '#')
			continue;
		while (opc != NULL)
		{
			arg = strtok(NULL, " ");

			if (arg != NULL && strcmp(arg, "push") == 0)
			{
				opc_sorter(arg);
				if (opc == NULL || opc[0] == '#')
					break;
				(*get_opc(opc, (int)ln))(&stack, ln);
				arg2 = strtok(NULL, " ");
				opc_sorter(arg2);
				if (arg == NULL || arg[0] == '#')
					break;
				(*get_opc(arg, (int)ln))(&stack, ln);
			}
			else

			{
				opc_sorter(arg);
				if (opc == NULL || opc[0] == '#')
					break;
				(*get_opc(opc, (int)ln))(&stack, ln);
				if (opc != NULL && strcmp(opc, "push") != 0)
				{
					if (arg == NULL || arg[0] == '#')
						break;
					(*get_opc(arg, (int)ln))(&stack, ln);
				}

			}
			opc = strtok(NULL, " ");
		}
	}

	free(data_lib);
	free_stack(stack);
	fclose(file);
	return (0);
}
/**
 * opc_sorter - sorts args into data_lib struct
 * @arg: opcode arguments
 * Return: nothing
 */
void opc_sorter(char *arg)
{
	int i, non_int = 0;

	for (i = 0; arg != NULL && arg[i] != '\0'; i++)
	{
		if (!(arg[i] == '-' || (arg[i] >= '0' && arg[i] <= '9')))
			non_int = 1;
	}
	if (arg != NULL && ((arg[0] == '-' && (arg[1] >= '0' && arg[1] <= '9')) ||
		(arg[0] >= '0' && arg[0] <= '9')) && non_int == 0)
	{
		data_lib->pushErr = 0;
		data_lib->value = atoi(arg);
	}
	else
	{
		data_lib->pushErr = 1;
	}
}
