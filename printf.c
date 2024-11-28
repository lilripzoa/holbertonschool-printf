#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * print_char - Affiche un caractère sur la sortie standard.
 * @c: Le caractère a afficher.
 *
 * Return: Le nombre de caractères affichés.
 */
int print_char(char c)
{
	return (write(1, &c, 1));  /* Affiche un seul caractère*/
}

/**
 * print_string - Affiche une chaine de caractères sur la sortie standard.
 * @str: La chaine de caractère a afficher.
 *
 * Return: Le nombre de caractère affichés.
 * Si la chaine est NULL, "(null)" est affiché.
 */

int print_string(char *str)
{
	int count = 0;

	if (!str) /* Vérifie si le pointeur str est NULL*/
	{
		str = "(null)";  /* Gère la chaîne NULL*/
	}
	while (*str) /* Parcours la chaine et affiche chaque caractère*/
	{
		write(1, str, 1);  /* Affiche caractère par caractère*/
		str++; /* Passe au caractère suivant*/
		count++; /* Incremente le compteur*/
	}
	return (count);
}

/**
 * print_number - Affiche un nombre entier.
 * @n: Le nombre a afficher.
 *
 * Return: Le nombre de caractère affiché.
 */
int print_number(int n)
{
	int count = 0;
	char buffer[11]; /* Stocker la répresentation du nombre*/
	int i = 0;

	if (n == 0) /* Si le nombre est 0*/
	{
		write(1, "0", 1);
		return (1);
	}
	if (n < 0) /* Si le nombre est negatif*/
	{
		write(1, "-", 1); /* Affiche le signe*/
		n = -n;
		count++;
	}
	/* Convertit l'entier en chaine*/
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0'; /* Stock chaque chiffre*/
		n /= 10;
	}
	/* Affiche les chiffres de gauche a droite*/
	while (i > 0)
	{
		write(1, &buffer[--i], 1);
		count++;
	}
	return (count);
}
/**
 * handle_format - gere l'affichage en fonction du specificateur de format
 * @specifier: spécificateur de format
 * @args: liste des arguments passé a la fonction _printf
 * Return: le nombre de caractere affiché
 */

int handle_format(char specifier, va_list args)
{
	int count = 0;

	if (specifier == 'c')  /* Gère %c */
	{
		count += print_char(va_arg(args, int));
	}
	else if (specifier == 's')  /* Gère %s */
	{
		count += print_string(va_arg(args, char *));
	}
	else if (specifier == 'd' || specifier == 'i')  /* Gère %d et %i */
	{
		count += print_number(va_arg(args, int));
	}
	else if (specifier == '%')  /* Gère %% */
	{
		count += print_char('%');
	}
	else  /* Spécificateur non pris en charge */
	{
		count += print_string("%r");
	}

	return (count);
}

/**
 * _printf - Imite la fonction printf pour des formats simple.
 * @format: La chaine de format.
 *
 * Return: Nombre de caractères imprimés.
 */
int _printf(const char *format, ...)
{
	va_list args; /* Liste des arguments */
	int count = 0; /* Nombre caractères affichés */
	const char *ptr;

	if (!format) /* Verifie si format est NULL*/
	{
		return (-1);
	}
	va_start(args, format); /* Initialise les arguments*/

	for (ptr = format; *ptr; ptr++) /* Parcours la chaine format*/
	{
		if (*ptr == '%') /* Trouve un format*/
		{
			ptr++; /* Passe au specificateur*/
			count += handle_format(*ptr, args);  /* Appelle handle_format */
		}
		else /* Si pas de %*/
		{
			count += print_char(*ptr); /* Affiche le caractère*/
		}
	}
	va_end(args); /* Libère les arguments*/
	return (count); /* Retourne le total de caractères affichés*/
}
