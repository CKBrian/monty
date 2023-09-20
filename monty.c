#include "monty.h"
#include <stdio.h>
/**
 * main - program entry point
 * @ac: argument count
 * @av: array of string arguments
 * Return: 0 always
 */
access_d *data_lib;
int main(int ac, char **av)
{
	char *tok, *tok1, buf[1024];
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
		tok = strtok(buf, " \n");
		tok1 = strtok(NULL, " \n");
		if (tok1 == NULL || !(tok1[0] >= '0' && tok1[0] <= '9'))
			data_lib->pushErr = 1;
		else
		{
			data_lib->pushErr = 0;
			data_lib->value = atoi(tok1);
		}
		ln++;
		(*get_opc(tok, (int)ln))(&stack, ln);
	}

	free(data_lib);
	free_stack(stack);
	fclose(file);
	return (0);

}
