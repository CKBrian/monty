#include "monty.h"
#include <stdio.h>
/**
 * main - program entry point
 * @ac: argument count
 * @av: array of string arguments
 * Return: 0 always
 */
access_d *data_lib;
void opc_sorter(char *arg);
int main(int ac, char **av)
{
	char *linetok, *opc, *arg, buf[1024];
	FILE *file;
	unsigned int ln = 0;
	stack_t *stack = NULL;

	if (ac != 2)
		printf("USAGE: monty file\n");


	file = fopen(av[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
	data_lib = malloc(sizeof(access_d));
	data_lib->file = file;
	if (data_lib == NULL)
		exit(EXIT_FAILURE);

	while (fgets(buf, sizeof(buf), file))
	{
		ln++;
		linetok = strtok(buf, "\n");
		opc = strtok(linetok, " ");
		while (opc)
		{
			arg = strtok(NULL, " ");
			/*printf("opc-> %s arg->%s\n", opc, arg);*/
			opc_sorter(arg);
			(*get_opc(opc, (int)ln))(&stack, ln);
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

	if (arg == NULL || !(arg[0] >= '0' && arg[0] <= '9'))
		data_lib->pushErr = 1;
	else
	{
		data_lib->pushErr = 0;
		data_lib->value = atoi(arg);
	}
}
