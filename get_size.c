#include "main.h"

/**
 * get_size - function that calulates the size to cast the argument
 * @format: Formatted string
 * @i: List of arguments to be printed
 *
 * Return: Precision.
 */


int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
<<<<<<< HEAD
	int sizee;
=======
int size;
>>>>>>> 92c53db3331be8f13c6acc5b7bc512eeb3a229ac

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;
	return (size);
}
