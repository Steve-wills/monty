#include "monty.h"
/**
 * m_pstr - prints the string starting at the top of the stack
 * @stack: Double linked list
 * @line_number: File line execution
 */
void m_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tsp = *stack;
	(void) line_number;

	if (!stack || !*stack)
	{
		putchar('\n');
		return;
	}
	while (tsp)
	{
		if (tsp->n == 0)
			break;
		if (!isascii((tsp)->n))
			break;
		putchar(tsp->n);
		tsp = tsp->next;
	}
	putchar('\n');
}

/**
 * m_rotl - rotates the stack to the top.
 * @stack: Double linked list
 * @line_number: File line execution
 */
void m_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *ts = *stack;
	(void) line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;
	(*stack)->next->prev = NULL;
	while (ts->next)
		ts = ts->next;
	ts->next = *stack;
	(*stack) = (*stack)->next;
	ts->next->next = NULL;
	ts->next->prev = ts;
}

/**
 * m_rotr - rotates the stack to the bottom.
 * @stack: Double linked list
 * @line_number: File line execution
 */
void m_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tsp;
	(void) line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	tsp = *stack;
	while (tsp->next)
		tsp = tsp->next;

	tsp->next = *stack;
	tsp->prev->next = NULL;
	tsp->prev = NULL;

	(*stack)->prev = tsp;
	*stack = tsp;
}
