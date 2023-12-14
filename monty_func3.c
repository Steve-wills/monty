#include "monty.h"

/**
 * m_swap - Delete top of list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
	int tsp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tsp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tsp;
}

/**
 * m_add - add the top two elements of the stack
 * @stack: Double linked list
 * @line_number: File line execution
 */
void m_add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	m_pop(stack, line_number);
}
