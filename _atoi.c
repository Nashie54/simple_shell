#include "shell.h"

/**
 * isInteractive - Checks if the shell is in interactive mode.
 * @shellInfo: Pointer to a struct containing shell information.
 *
 * Return: 1 if in interactive mode, 0 otherwise.
 */
int isInteractive(info_t *shellInfo)
{
	return (isatty(STDIN_FILENO) && shellInfo->readDescriptor <= 2);
}

/**
 * isDelimiter - Checks if a character is a delimiter.
 * @character: The character to check.
 * @delimiterStr: The delimiter string.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int isDelimiter(char character, char *delimiterStr)
{
	while (*delimiterStr)
		if (*delimiterStr++ == character)
			return (1);
	return (0);
}

/**
 * isAlphabetic - Checks if a character is alphabetic.
 * @character: The character to check.
 *
 * Return: 1 if character is alphabetic, 0 otherwise.
 */
int isAlphabetic(int character)
{
	if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * stringToInteger - Converts a string to an integer.
 * @inputString: The string to be converted.
 *
 * Return: 0 if no numbers are found in the string, the converted number otherwise.
 */
int stringToInteger(char *inputString)
{
	int index, sign = 1, flag = 0, result;
	unsigned int convertedNumber = 0;

	for (index = 0;  inputString[index] != '\0' && flag != 2; index++)
	{
		if (inputString[index] == '-')
			sign *= -1;

		if (inputString[index] >= '0' && inputString[index] <= '9')
		{
			flag = 1;
			convertedNumber *= 10;
			convertedNumber += (inputString[index] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		result = -convertedNumber;
	else
		result = convertedNumber;

	return (result);
}

