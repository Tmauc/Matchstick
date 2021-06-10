/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** error.c
*/

#include "match.h"

int check_error(char **av)
{
	if ((str_to_int(av[1]) * 2 - 1) < str_to_int(av[2])) {
		return (84);
	} if (str_to_int(av[1]) <= 1 || str_to_int(av[1]) > 99 ||
	str_to_int(av[2]) < 1) {
		return (84);
	} else
		return (0);
}
