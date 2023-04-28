#include "main.h"

/**
 * handle_print - print an argument based on its type
 * @format: formatted string in which to print the argument
 * @list: list of argument to be printed
 * @index: index
 * @buffer: buffer array to handle print
 * @flag: calculates active flags
 * @width: get width
 * @prec: precision specification
 * @size: size specification
 * Return: 1 or 2
 */
int handle_print(const char *format, int *index, va_list list, char buffer[],
int flag, int width, int prec, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	format_t format_types[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_perc},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hupper}, {'p', print_pointer}, {'s', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13edstring}, {'\0', NULL}
	};
	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*index] == format_types[i].format)
			return (format_types[i].func(list, buffer, flag, width, prec, size));

	if (format_types[i].format == '\0')
	{
		if (format[*index - 1] == ' ')
			unknow_len += write(1, " ", 1);

		if (format[*index] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);

		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != %)
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		unknow_len += write(1, &fmt[*index], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
