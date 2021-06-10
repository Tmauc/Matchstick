/*
** EPITECH PROJECT, 2018
** setup.c
** File description:
** setup.c
*/

#include "match.h"

void loop_nbr_matches(match_t *m, int i)
{
	for (int j = 0; m->map[i][j] != '\0'; j++)
		if (m->map[i][j] == '|')
			m->nbr_matches += 1;
}

void get_nbr_matches(match_t *m)
{
	for (int i = 0; m->map[i] != NULL; i++)
		loop_nbr_matches(m, i);
}

void setup(match_t *m, char **av)
{
	m->height = str_to_int(av[1]) + 2;
	m->width = str_to_int(av[1]) * 2 + 1;
	m->rmv_max = str_to_int(av[2]);
	m->nbr_turn = 0;
	m->nbr_match += 1;
	m->restart = 0;
	get_map(m);
	get_nbr_matches(m);
}
