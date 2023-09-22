#include "monty.h"
/**
 * get_opc - returns the function corresponding to the opcode
 * @opc: opecode
 * @ln: line number
 * Return: function pointer
 */
void (*get_opc(char *opc, int ln))(stack_t **stack, unsigned int line_number)
{
	instruction_t optn[] = {
		{"push", push_stack},
		{"Push", push_stack},
		{"pall", print_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"nop", nop_stack},
		{"add", add_stack},
		{"mul", mul_stack},
		{"div", div_stack},
		{"mod", mod_stack},
		{"sub", sub_stack},
		{"pchar", pchar_stack},
		{"pstr", pstr_stack},
		{"swap", swap_stack},
	};
	int i = 0;

	while (i < 13)
	{
		if (opc != NULL && strcmp(opc, optn[i].opcode) == 0)
			return (optn[i].f);
		i++;
	}
	if (i == 13)
	{
		fprintf(stderr, "%d: unknown instruction %s\n", ln, opc);
		if (*(data_lib->stack))
			free_stack(*(data_lib->stack));
		fclose(data_lib->file);
		free(data_lib);
		exit(EXIT_FAILURE);
	}
	return (NULL);
}
