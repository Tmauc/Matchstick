/*
** EPITECH PROJECT, 2018
** my_strchr.c
** File description:
** if a chr is in a str
*/

#include "match.h"

int my_strchr(char *str, char chr)
{
	int i = 0;
	int result = 0;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == chr)
			result += 1;
	}
	return (result);
}
