# PRINTF

## Description
 
The project is to create a function called _printf, which mimics the behavior of the standard printf function in C. This involves implementing the ability to print various types of data (such as integers, strings, characters, etc.) by processing format specifiers, managing variable arguments, and handling edge cases like null pointers or unsupported specifiers. The goal is to develop a custom implementation of printf that can handle multiple formatting options and display the correct output based on user input

## The language used

![C](https://img.shields.io/badge/language-C-blue)

```
#include <stdio.h>

int main()
{
    printf("Hello world");
}
```
## Installation

Clone the repository and compile the code with `gcc` :

```
$ git clone https://github.com/lilripzoa/holbertonschool-printf.git
$ cd holbertonschool-printf
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
$ ./holbertonschool-printf
```
    
## Authorized functions and macros

In this project, only certain functions are allowed to implement the `_printf` function:

- `write` (man 2 write) : Écrit des données sur la sortie standard.
- `malloc` (man 3 malloc) : Alloue de la mémoire dynamique.
- `free` (man 3 free) : Libère la mémoire allouée.
- `va_start` (man 3 va_start) : Initialise l'accès aux arguments variadiques.
- `va_end` (man 3 va_end) : Termine l'accès aux arguments variadiques.
- `va_copy` (man 3 va_copy) : Copie une liste d'arguments variadiques.
- `va_arg` (man 3 va_arg) : Récupère un argument variadique spécifique.

These functions allow you to handle arguments passed to the `_printf` function and to directly manipulate program output without using features of the standard C library other than those explicitly allowed.
## Example of test file that you could use:

```
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
```

### This file tests different format specifiers, including:
    
`%d` and `%i` for integers,

`%u` for unsigned integers,

`%o` for octals,

`%x` and `%X` for hexadecimals,

`%c` for characters,

`%s` for strings,

`%p` for pointers,

`%%` for the `%` character.
