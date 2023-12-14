#include "monty.h"

/**
 * m_mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: Double linked list
 * @line_number: File line execution
 */
void m_mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	m_pop(stack, line_number);
}


/**
 * m_mod - computes the rest of the division
 * @stack: Double linked list
 * @line_number: File line execution
 */
void m_mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	m_pop(stack, line_number);
}


/**
 * m_pchar - prints the char at the top of the stack
 * @stack: Double linked list
 * @line_number: File line execution
 */
void m_pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (isascii((*stack)->n))
	{
		printf("%c\n", (*stack)->n);
		return;
	}
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}
