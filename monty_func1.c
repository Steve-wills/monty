#include "monty.h"
/**
 * m_push - Insert a new value in list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tsp = NULL, *ts = *stack;
	char *nums;

	nums = strtok(NULL, " \r\t\n");
	if (nums == NULL || (_isdigit(nums) != 0 && nums[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tsp = malloc(sizeof(stack_t));
	if (!tsp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	tsp->n = atoi(nums);
	if (var.MODE == 0 || !*stack)
	{
		tsp->next = *stack;
		tsp->prev = NULL;
		if (*stack)
			(*stack)->prev = tsp;
		*stack = tsp;
	}
	else
	{
		while (ts->next)
			ts = ts->next;
		ts->next = tsp;
		tsp->prev = ts;
		tsp->next = NULL;
	}
}
/**
 * m_pall - Print list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tsp = *stack;
	(void) line_number;

	if (!tsp)
		return;
	while (tsp)
	{
		printf("%d\n", tsp->n);
		tsp = tsp->next;
	}
}
