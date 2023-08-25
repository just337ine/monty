#include "monty.h"

/**
 * is_integer - Checks if a string represents a valid integer.
 * @str: String being checked
 * Return: 1 if it's a valid integer, 0 otherwise
 */
int is_integer(char *str)
{
	unsigned int i = 0;

	if (str == NULL)
		return (0);
	if (str[i] == '-')
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
