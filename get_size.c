#include "main.h"



/**
 * get_size - function to calulates the size
 * @format: Formatted string
 * @i: List of arguments to be printed
 *
 * Return: precision
 *
 */


int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int sizee;

	if (format[curr_i] == 'l')
		sizee = S_LONG;

	else if (format[curr_i] == 'h')
		sizee = S_SHORT;

	if (sizee == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;
	return (sizee);
}
