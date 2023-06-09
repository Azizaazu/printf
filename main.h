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
 * struct fmt - Struct op
 *
 * @fmt: format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @format: The format.
 * @func_t: The function associated.
 */
typedef struct fmt fmt_t;
int _printf(const char *format, ...);

int handle_print(const char *fmt, int *i, va_list list, char buffer[], int flag, int width, int prec, int size);

/*Functions */
/* Functions for numbers */
int print_unsigned_number(va_list type, char buffer[], int flag, int width, int prec, int size);
int print_octal_number(va_list type, char buffer[], int flag, int width, int prec, int size);
int print_hexa_number(va_list type, char map_to[],char buffer[], int flag, char flag_ch, int width, int prec, int size);
int print_hexadecimal_number(va_list type, char buffer[], int flag, int width, int prec, int size);
int print_int(va_list type, char buffer[], int flag, int width, int prec, int size);
int print_binar(va_list type, char buffer[], int flag, int width, int prec, int size);
int print_hupper_number(va_list type, char buffer[], int flag, int width, int prec, int size);
/* Funtions for chars and strings */
int print_str(va_list type, char buffer[], int flag, int width, int prec, int size);
int print_char(va_list type, char buffer[], int flag, int width, int prec, int size);
int print_perct(va_list type, char buffer[], int flag, int width, int prec, int size);
/*utils.c*/
int is_digit(char);
int if_num_is_printable(char);
long int convert_size_unsgnd(unsigned long int n, int size);
int append_hexa_code(char, char[], int);
long int convert_size_number(long int n, int size);
/* Function for non printable char */
int print_non_printable_number(va_list type, char buffer[], int flag, int width, int prec, int size);
/*Function to print string in reverse*/
int print_reverse_number(va_list type, char buffer[], int flag, int width, int prec; int size);
/* Function for  memory address */
int print_pointer(va_list type, char buffer[], int flag, int width, int prec, int size);
/*Function to print a string in rot 13*/
int print_rot13edstring(va_list type, char buffer[], int flag, int width, int prec, int size);
/* width handler */
int write_pointer(char buffer[], int index, int l, int width, int flag, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int index, char buffer[], int flag, int width, int prec, int size);
int handle_write_char(char c, char buffer[], int flag, int width, int prec, int size);
int write_number(int is_positive, int index, char buffer[], int flag, int width, int prec, int size);
int write_num(int ind, char bff[], int flag, int width, int prec, int l, char padd, char extra_c);
/* handle other specifiers */
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int get_flag(const char *format, int *i);

#endif
