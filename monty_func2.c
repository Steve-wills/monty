#include "monty.h"
/**
 * m_pint - Print last node
 * @stack: Double linked list
 * @line_number: File line execution
 */
void m_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* m_pop - Delete top of list
* @stack: Double linked list
* @line_number: File line execution
*/
void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tsp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	tsp = *stack;
	*stack = tsp->next;
	if (tsp->next)
		tsp->next->prev = NULL;
	free(tsp);
}
