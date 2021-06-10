/*
** EPITECH PROJECT, 2018
** remove_matches_player.c
** File description:
** remove_matches_player.c
*/

#include "match.h"

int remove_matches_player(match_t *m)
{
	for (int i = m->width; i != 0 && m->matches != 0; i--)
		if (m->map[m->line][i] == '|') {
			m->map[m->line][i] = ' ';
			m->matches -= 1;
			m->nbr_matches -= 1;
		}
	if (m->nbr_matches <= 0) {
		print_map_loos(m);
		return (2);
	} else
		return (0);
}
