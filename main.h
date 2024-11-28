#ifndef MAIN_H
#define MAIN_H

#include "main.h"
#include <stdarg.h>
#include <unistd.h> /* pour ecrire*/

int _printf(const char *format, ...);
int print_char(char c); /* Prototype de print_char*/
int print_string(char *str); /* Prototype de print_string*/
int handle_format(char specifier, va_list args); /*prototype de handle_format*/

#endif /* MAIN_H */
