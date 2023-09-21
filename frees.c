#include "shell.h"

/**
 * frees_get_env - Frees an environment variable.
 * @env_path: The environment variable to free.
 *
 * Return: Nothing.
 */
void frees_get_env(char *env_path)
{
	int i;

	for (i = 4; i >= 0; i--)
		env_path--;

	free(env_path);
}

/**
 * frees_tokens - Frees an array of tokens.
 * @tokns: The array of tokens to free.
 *
 * Return: Nothing.
 */
void frees_tokens(char **tokns)
{
	char **temp = tokns;

	if (tokns)
	{
		while (*tokns)
			free(*tokns++);

		free(temp);
	}
}
