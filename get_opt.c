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
		{"nop", nop_stack},
		{"push", push_stack},
		{"pall", print_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"rotl", rotl_stack},
		{"rotr", rotr_stack},
		{"add", add_stack},
		{"mul", mul_stack},
		{"div", div_stack},
		{"mod", mod_stack},
		{"sub", sub_stack},
		{"pchar", pchar_stack},
		{"queue", to_queue},
		{"stack", to_stack},
		{"pstr", pstr_stack},
		{"swap", swap_stack},
	};
	int i = 0, unknown = 0;

	while (i < 17)
	{
		if (opc != NULL && strcmp(opc, optn[i].opcode) == 0)
		{
			if (strcmp(opc, "pall") != 0)
				data_lib->history = 0;
			return (optn[i].f);
		}
		if (strncmp(opc, optn[i].opcode, strlen(optn[i].opcode)) == 0)
			unknown = 1;
		i++;
	}
	data_lib->history = 1;
	if (i == 17 && opc && unknown == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, opc);
		if (*(data_lib->stack))
			free_stack(*(data_lib->stack));
		fclose(data_lib->file);
		free(data_lib);
		exit(EXIT_FAILURE);
	}
	return (optn[0].f);
}
