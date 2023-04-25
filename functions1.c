#include "main.h"
/************************* PRINT UNSIGNED NUMBER ***********************/
/**
 * print_unsigned - print an unsigned number
 * @types: lista of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of char printed
 */
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/***************************PRINT UNSIGNED NUMBER IN OCTAL****************/

/**
 * print_octal - print an unsigned number in octal notation
 * @types: lista of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of char printed
 */
int print_octal(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/************* PRINT UNSIGNED NUMBER IN HEXADECIMAL ****************/
/**
 * print_hexadecimal - print an unsigned number in hexa notation
 * @types: lista of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of char printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags,
	'x', width, precision, size));
}
/************ PRINT UNSIGNED NUMBER IN UPPER HEX NOTATION*************/
/**
 * print_hexa_upper - print an unsigned number in upper hexa notation
 * @types: lista of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of char printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags,
	'X', width, precision, size));
}
/************** PRINT HEX NUM IN LOWER OR UPPER *******************/
/**
 * print_hexa - print an hexa nmbr in upper or lower
 * @types: lista of arguments
 * @map_to: array of values to map the number
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @flag_ch: calculate active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of char printed
 */
int print_hexa(va_list types,char map_to[], char buffer[], int flags,
int flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
