#include "monty.h"

/**
 * varStart - start vars
 * @var: Global variables to initialize
 * Return: 0 Success, 1 Failed
 */
int varStart(varbl *var)
{
	var->file = NULL;
	var->buff = NULL;
	var->tsp = 0;
	var->dictn = create_inst();
	if (var->dictn == NULL)
		return (EXIT_FAILURE);
	var->head = NULL;
	var->line_number = 1;
	var->MODE = 0;

	return (EXIT_SUCCESS);
}

/**
 * create_inst - Create new functions dictionary
 * Return: Dictionary pointer
 */
instruction_t *create_inst()
{
	instruction_t *pt = malloc(sizeof(instruction_t) * 18);

	if (!pt)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	pt[0].opcode = "pall", pt[0].f = m_pall;
	pt[1].opcode = "push", pt[1].f = m_push;
	pt[2].opcode = "pint", pt[2].f = m_pint;
	pt[3].opcode = "pop", pt[3].f = m_pop;
	pt[4].opcode = "swap", pt[4].f = m_swap;
	pt[5].opcode = "add", pt[5].f = m_add;
	pt[6].opcode = "nop", pt[6].f = NULL;
	pt[7].opcode = "sub", pt[7].f = m_sub;
	pt[8].opcode = "div", pt[8].f = m_div;
	pt[9].opcode = "mul", pt[9].f = m_mul;
	pt[10].opcode = "mod", pt[10].f = m_mod;
	pt[11].opcode = "pchar", pt[11].f = m_pchar;
	pt[12].opcode = "pstr", pt[12].f = m_pstr;
	pt[13].opcode = "rotl", pt[13].f = m_rotl;
	pt[14].opcode = "rotr", pt[14].f = m_rotr;
	pt[15].opcode = "stack", pt[15].f = m_stack;
	pt[16].opcode = "queue", pt[16].f = m_queue;
	pt[17].opcode = NULL, pt[17].f = NULL;

	return (pt);
}

/**
 * funcs_call - Call Functions
 * @var: Global variables
 * @opcode: Command to execute
 * Return: None
 */
int funcs_call(varbl *var, char *opcode)
{
	int i;

	for (i = 0; var->dictn[i].opcode; i++)
		if (strcmp(opcode, var->dictn[i].opcode) == 0)
		{
			if (!var->dictn[i].f)
				return (EXIT_SUCCESS);
			var->dictn[i].f(&var->head, var->line_number);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			var->line_number, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
