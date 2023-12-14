#include "monty.h"

varbl var;

/**
 * main - Start LIFO, FILO program
 * @ac: Number of arguments
 * @av: Pointer containing arguments
 * Return: 0 Success, 1 Failed
 */
int main(int ac, char **av)
{
	char *opcode;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (varStart(&var) != 0)
		return (EXIT_FAILURE);

	var.file = fopen(av[1], "r");
	if (!var.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free_all();
		return (EXIT_FAILURE);
	}

	while (getline(&var.buff, &var.tsp, var.file) != EOF)
	{
		opcode = strtok(var.buff, " \r\t\n");
		if (opcode != NULL)
			if (funcs_call(&var, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		var.line_number++;
	}

	free_all();

	return (EXIT_SUCCESS);
}
