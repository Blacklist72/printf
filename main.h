#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * _putchar - write character c to the stdout
 * @c: the character
 * Return: 1 on success and -1 otherwise
 */
int _putchar(char c);

/**
 * struct frmat - Struct objct
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct frmat
{
	char frmat;
	int (*fn)(va_list, char[], int, int, int, int);
};

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/*buffer print*/
void print_buffer(char buffer[], int *buffr_ind);

/**
 * typedef struct frmat frmatn - Struct frmatn
 *
 * @frmat: The format.
 * @frmatn: The function associated.
 */
typedef struct frmat frmatn;

/**
 * _printf - my custom prints function
 *
 * @format: format.
 * Return - int
 */
int _printf(const char *format, ...);
int handle_print(const char *frmat, int *i,
		va_list list, char buffer[], int flags, int width, int precision, int size);

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int str_print(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int percent_print(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int bin_print(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int unsign_print(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int oct_print(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int hexa_dec_print(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int hexa_upper_print(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int hexa_print(va_list types, char map_to[],
		char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int non_printable_char_print(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* SIZES */
#define SIZE_L 2
#define SIZE_S 1

/* Funcion to print memory address */
int print_ptr(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int specifier_flags(const char *format, int *i);
int specifier_width(const char *format, int *i, va_list list);
int specifier_precision(const char *format, int *i, va_list list);
int specifier_size(const char *format, int *i);

/*Function to print string in reverse*/
int reverse_str(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int rot13_str(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int write_char_handler(char c, char buffer[],
		int flags, int width, int precision, int size);
int write_number_handler(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_number1_handler(int ind, char bff[], int flags, int width, int precision,
		int length, char padd, char extra_c);
int write_pointer_handler(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd_handler(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size);
int check_if_printatble(char);
int append_hexa_code_util(char, char[], int);
int is_digit(char);

long int convert_number_size(long int num, int size);
long int convert_unsgned_size(unsigned long int num, int size);

#define NOT_USED(q) (void)(q)
#define BUFFR_SIZE 1024

#endif

