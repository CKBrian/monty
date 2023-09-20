#include "monty.h"
#include <stdio.h>
/**
 * main - program entry point
 * @ac: argument count
 * @av: array of string arguments
 * Return: 0 always
 */
int globvalue;
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

	while (fgets(buf, sizeof(buf), file))
	{
		tok = strtok(buf, " \n");
		tok1 = strtok(NULL, " \n");
		if (tok1 == NULL)
			tok1 = "\0";
		globvalue = atoi(tok1);
		ln++;
		(*get_opc(tok, (int)ln))(&stack, ln);
	}

	free(stack);
	fclose(file);
	return (0);

}
