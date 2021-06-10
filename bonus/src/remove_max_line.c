/*
** EPITECH PROJECT, 2018
** remove_max_matches.c
** File description:
** remove_max_matches.c
*/

#include "match.h"

int remove_max_matches_part2(match_t *m, int size)
{
	for (int i = 0; m->map[i] != NULL; i++) {
		if (get_nbr_matches_ia(m, i) >= size) {
			m->line_ai = i;
			m->matches_ai = size;
			return (0);
		}
	}
	return (1);
}

int remove_max_matches(match_t *m)
{
	int size = m->rmv_max;

	while (size != 0) {
		if (remove_max_matches_part2(m, size) == 0)
			return (0);
		size--;
	}
	return (0);
}
