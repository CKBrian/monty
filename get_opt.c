#include "monty.h"
/**
 * get_opc - returns the function corresponding to the opcode
 * @opc: opecode
 * @ln: line number
 * @s: stack pointer
 * Return: function pointer
 */
void (*get_opc(stack_t *s, char *opc, int ln))(stack_t **stack, unsigned int line_number)
{
	instruction_t optn[] = {
		{"push", push_stack},
		{"pall", print_stack},
		{"pop", pop_stack},
	};
	int i = 0;

	while (i < 3)
	{
		/*printf("--%s--%s-\n", opc, optn[i].opcode);*/
		if (strcmp(opc, optn[i].opcode) == 0)
			return (optn[i].f);
		i++;
	}
	if (i == 3)
	{
		fprintf(stderr, "%d: unknown instruction %s\n", ln, opc);
		free_stack(s);
		data_lib->stack = NULL;
		fclose(data_lib->file);
		free(data_lib);
		exit(EXIT_FAILURE);
	}
	return (NULL);
}
