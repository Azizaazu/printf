#include "main.h"

/* UNSIGNED NUMBER IN OCTAL */
/**
 * print_octal_number - print an unsigned number in octal
 * @type: list of arguments
 * @buffer: buffer array
 * @flag: calculates active flags
 * @width: get width
 * @prec: precision specification
 * @size: size specifier
 * Return: number of char printed
 *
 */
int print_octal_number(va_list type, char buffer[], int flag,
int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(type, unsigned long int);
	unsigned long int init_n = n;

	UNUSED(width);
	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[i--] = (n % 8) + '0';
		n /= 8;
	}
	if (flag & F_HASH && init_n != 0)
		buffer[i--] = '0';

	i++;
	return (write_unsgnd(0, i, buffer, flag, width, prec, size));
}
/*  UNSIGNED NUMBER IN UPPER HEX */
/**
 * print_hupper_number - print an unsigned number in upper hexa
 * @type: lista of arguments
 * @buffer: buffer array
 * @flag: calculates active flags
 * @width: get width
 * @prec: precision specification
 * @size: size specifier
 * Return: number of char printed
 *
 */
int print_hupper_number(va_list type, char buffer[], int flag,
int width, int prec, int size)
{
	return (print_hexa(type, "0123456789ABCDEF", buffer, flag,
	'X', width, prec, size));
}

/* UNSIGNED NUMBER IN HEXADECIMAL */
/**
 * print_hexadecimal_number - print an unsigned number in hexa
 * @type: list of arguments
 * @buffer: buffer array
 * @flag: calculates active flags
 * @width: get width
 * @prec: precision specification
 * @size: size specifier
 * Return: number of char printed
 *
 */
int print_hexadecimal_number(va_list type, char buffer[], int flag,
int width, int prec, int size)
{
	return (print_hexa(type, "0123456789abcdef", buffer, flag,
	'x', width, prec, size));
}

/* HEX NUM IN LOWER OR UPPER */
/**
 * print_hexa_number - print an hexa nmbr in upper or lower
 * @type: list of arguments
 * @map_to: array of values to map the number
 * @buffer: buffer array to handle print
 * @flag: calculates active flags
 * @flag_ch: calculate active flags
 * @width: get width
 * @prec: precision specification
 * @size: size specifier
 * Return: number of char printed
 *
 */
int print_hexa_number(va_list type, char map_to[], char buffer[], int flag,
char flag_ch, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(type, unsigned long int);
	unsigned long int init_n = n;

	UNUSED(width);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[i--] = map_to[n % 16];
		n /= 16;
	}
	if (flags & F_HASH && init_n != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;
	return (write_unsgnd(0, i, buffer, flag, width, prec, size));
}
/* PRINT UNSIGNED NUMBER */
/**
 * print_unsigned_number - print an unsigned number
 * @type: list of arguments
 * @buffer: buffer array
 * @flag: calculates active flags
 * @width: get width
 * @prec: precision specification
 * @size: size specifier
 * Return: number of char printed
 *
 */
int print_unsigned_number(va_list type, char buffer[],
int flag, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(type, unsigned long int);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flag, width, prec, size));
}
