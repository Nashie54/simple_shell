#include "shell.h"

/**
 * _handle_exit - Handles the exit command.
 * @u_tokens: The user tokens.
 * @line: The input line.
 *
 * Return: Nothing.
 */
void _handle_exit(char **u_tokens, char *line)
{
	int status = 0;

	if (u_tokens[1] == NULL || (!_strcmp(u_tokens[1], "0")))
	{
		frees_tokens(u_tokens);
		free(line);
		exit(0);
	}
	status = _atoi(u_tokens[1]);
	if (status != 0)
	{
		frees_tokens(u_tokens);
		free(line);
		exit(status);
	}
	else
	{
		_puts("exit: Illegal number: ");
		_puts(u_tokens[1]);
		_puts("\n");
		exit(2);
	}

	frees_tokens(u_tokens);
	free(line);
	exit(EXIT_SUCCESS);
}

