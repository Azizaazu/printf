#include "main.h"



void print_buff(char buffer[], int *buff_ind);

/**
 * _printf - printf function
 * @format: format.
 * Return: Printed chars
 *
 */
int _printf(const char *format, ...)
{
	int m, printed = 0, printed_chars = 0;
	int flag, width, prec, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (m = 0; format && format[m] != '\0'; m++)
	{
		if (format[m] != '%')
		{
			buffer[buff_ind++] = format[m];
			if (buff_ind == BUFF_SIZE)
				print_buff(buffer, &buff_ind);

			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flag = get_flag(format, &m);
			width = get_width(format, &m, list);
			prec = get_precision(format, &m, list);
			size = get_size(format, &m);
			++m;
			printed = handle_print(format, &m, list, buffer,
				flag, width, prec, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buff(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}

/**
 * print_buff - prints content of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char
 *
 */
void print_buff(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
