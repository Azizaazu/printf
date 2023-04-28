#ifndef MAIN_H
#define MAIN_H
#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/* size */
#define S_LONG 2
#define S_SHORT 1
/* flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct format - Struct op
 *
 * @format: format.
 * @func: The function associated.
 */
struct format
{
	char format;
	int (*func)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @format: The format.
 * @func_t: The function associated.
 */
typedef struct format func_t;
int _printf(const char *fmt, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flag, int width, int prec, int size);

/*Functions */
/* Functions for numbers */
int print_unsigned_number(va_list types, char buffer[],
        int flag, int width, int prec, int size);
int print_octal_number(va_list types, char buffer[],
        int flag, int width, int prec, int size);
int print_hexa_number(va_list types, char map_to[],
char buffer[], int flag, char flag_ch, int width, int prec, int size);
int print_hexadecimal_number(va_list types, char buffer[],
        int flag, int width, int prec, int size);
int print_int(va_list types, char buffer[],
	int flag, int width, int prec, int size);
int print_binary(va_list types, char buffer[],
	int flag, int width, int prec, int size);
int print_hupper_number(va_list types, char buffer[],
	int flag, int width, int prec, int size);
/* Funtions for chars and strings */
int print_str(va_list types, char buffer[],
        int flag, int width, int prec, int size);
int print_char(va_list types, char buffer[],
        int flag, int width, int prec, int size);
int print_perc(va_list types, char buffer[],
        int flag, int width, int prec, int size)
/*utils.c*/
int is_digit(char);
int if_num_is_printable(char);
long int convert_size_unsgnd(unsigned long int n, int size);
int append_hexa_code(char, char[], int);
long int convert_size_number(long int n, int size);
/* Function for non printable char */
int print_non_printable_number(va_list types, char buffer[],
	int flag, int width, int prec, int size);
/*Function to print string in reverse*/
int print_reverse_number(va_list types, char buffer[],
        int flag, int width, int prec; int size);
/* Function for  memory address */
int print_pointer(va_list types, char buffer[],
	int flag, int width, int prec, int size);
/*Function to print a string in rot 13*/
int print_rot13edstring(va_list types, char buffer[],
	int flag, int width, int prec, int size);
/* width handler */
int write_pointer(char buffer[], int ind, int length,
        int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size);
int handle_write_char(char c, char buffer[],
	int flag, int width, int prec, int size);
int write_number(int is_positive, int index, char buffer[],
	int flag, int width, int prec, int size);
int write_num(int ind, char bff[], int flag, int width, int prec,
	int l, char padd, char extra_c);
/* handle other specifiers */
int get_width(const char *fmt, int *i, va_list list);
int get_precision(const char *fmt, int *i, va_list list);
int get_size(const char *frmt, int *i);
int get_flags(const char *format, int *i);

#endif
