/*
** EPITECH PROJECT, 2018
** my_putcharror.c
** File description:
** putchar on error output
*/

#include "match.h"

void my_putcharror(char chr)
{
	write(2, &chr, 1);
}
