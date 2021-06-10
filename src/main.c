/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "match.h"

int main(int ac, char **av)
{
	match_t m = {NULL, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	srand(time(NULL));
	if (ac != 3)
		return (84);
	if (check_error(av) == 0) {
		setup(&m, av);
		return (prog(&m));
	}
	free_struct(&m);
	return (84);
}
