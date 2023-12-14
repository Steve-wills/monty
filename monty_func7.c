#include "monty.h"
/**
 * m_stack - sets the format of the data to a stack (LIFO)
 * @stack: Double linked list
 * @line_number: File line execution
 */
void m_stack(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	var.MODE = 0;
}

/**
 * m_queue - sets the format of the data to a queue (FIFO)
 * @stack: Double linked list
 * @line_number: File line execution
 */
void m_queue(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	var.MODE = 1;
}
