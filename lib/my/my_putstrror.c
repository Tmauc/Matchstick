/*
** EPITECH PROJECT, 2018
** my_put_strror.c
** File description:
** print a string on error output
*/

#include "match.h"

void my_putstrror(char *str)
{
	write(2, str, my_strlen(str));
}
