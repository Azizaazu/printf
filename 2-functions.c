#include "main.h"

/* REVERSE */
/**
 * print_reverse_number - function to prints reverse string.
 * @type: List of arguments
 * @buffer: Buffer array
 * @flag: calculates active flags
 * @width: get width
 * @prec: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 *
 */
int print_reverse_number(va_list type, char buffer[],
int flag, int width, int prec, int size)
{
	char *string;
	int i, c = 0;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(size);

	string = va_arg(type, char *);

	if (string == NULL)
	{
		UNUSED(prec);

		string = ")Null(";
	}
	for (i = 0; string[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = string[i];

		write(1, &z, 1);
		c++;
	}
	return (c);
}

/* POINTER */
/**
 * print_pointer - function to prints the value of a pointer variable
 * @type: List of arguments
 * @buffer: Buffer array
 * @flag: calculates active flags
 * @width: get width
 * @prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 *
 */
int print_pointer(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	char extra_c = 0, padd = ' ';
	int i = BUFF_SIZE - 2, l = 2, padd_start = 1;
	unsigned long n_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(type, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(prec);

	n_addrs = (unsigned long)addrs;

	while (n_addrs > 0)
	{
		buffer[i--] = map_to[n_addrs % 16];
		n_addrs /= 16;
		l++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';
	if (flag & F_PLUS)
		extra_c = '+', l++;
	else if (flag & F_SPACE)
		extra_c = ' ', l++;

	i++;

	return (write_pointer(buffer, i, l, width, flag,
	padd, extra_c, padd_start));
}

/* NON PRINTABLE */
/**
 * print_non_printable_number - function to prints ascci codes
 * in hexa of non print chars
 * @type: List of arguments
 * @buffer: Buffer array to handle print
 * @flag: Calculates active flags
 * @width: get width
 * @prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 *
 */
int print_non_printabl_number(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	int i = 0, offset = 0;
	char *string = va_arg(type, char *);

	UNUSED(flag);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	if (string == NULL)
		return (write(1, "(null)", 6));

	while (string[i] != '\0')
	{
		if (is_printable(string[i]))
			buffer[i + offset] = string[i];
		else
			offset += append_hexa_code(string[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/* STRING IN ROT13 */
/**
 * print_rot13edstring - function to print a string in rot13.
 * @type: Lista of arguments
 * @buffer: Buffer array
 * @flag: calculates active flags
 * @width: get width
 * @prec: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 *
 */
int print_rot13edstring(va_list type, char buffer[],
	int flag, int width, int prec, int size)
{
	char a;
	char *string;
	unsigned int i, j;
	int c = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	if (string == NULL)
		string = "(AHYY)";
	for (i = 0; string[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == string[i])
			{
				a = out[j];
				write(1, &a, 1);
				c++;
				break;
			}
		}
		if (!in[j])
		{
			a = string[i];
			write(1, &a, 1);
			c++;
		}
	}
	return (c);
}
