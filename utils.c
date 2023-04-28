#include "main.h"

/**
 * is_digit - verifies if a char is a digit
 * @count: char to be verified
 * Return: 1 if count is digit, 0 otherwise
 */
int is_digit(char count)
{
	if (count >= '0' && count <= '9')
		return (1);

	return (0);
}
/**
 * convert_size_unsgnd - casts a number to specified size
 * @n: number to be casted
 * @size: number indicating the type to be casted
 * Return: casted value of num
 */
long int convert_size_unsgnd(unsigned long int n, int size)
{
	if (size == S_LONG)
		return (n);
	else if (size == S_SHORT)
		return ((unsigned short)n);

	return ((unsigned int)n);
}
/**
 * if_num_is_printable - evaluates if a char is printable
 * @count: char to be evaluated
 * Return: 1 if c is printable, 0 otherwise
 */
int if_num_is_printable(char count)
{
	if (count >= 32 && count < 127)
		return (1);
	return (0);
}
/**
 * append_hexa_code - append ascci in hexadecimal code buffer
 * @buffer: array of chars
 * @i: index at which to start appending
 * @ascci_code: ASSCI CODE
 * Return: always 3
 */
int append_hexa_code(char ascci_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascci_code < 0)
		ascci_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascci_code / 16];
	buffer[i] = map_to[ascci_code % 16];

	return (3);
}
/**
 * convert_size_number - casts a number to specified size
 * @n: number to be casted
 * @size: number indicating the type to be casted
 * Return: casted value of num
 */
long int convert_size_number(long int n, int size)
{
	if (size == S_LONG)
		return (n);
	else if (size == S_SHORT)
		return ((short)n);

	return ((int)n);
}
