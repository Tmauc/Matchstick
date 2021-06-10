/*
** EPITECH PROJECT, 2018
** compt_line.c
** File description:
** compt_line.c
*/

#include "match.h"

int get_nbr_matches_ia(match_t *m, int line)
{
	int compter = 0;

	for (int i = 0; m->map[line][i] != '\0'; i++)
		if (m->map[line][i] == '|')
			compter++;
	return (compter);
}

int check_size_algo1(match_t *m, int lone)
{
	int nbr_lo = get_nbr_matches_ia(m, lone);

	if (nbr_lo <= m->rmv_max) {
		m->line_ai = lone;
		m->matches_ai = nbr_lo - 1;
		return (1);
	}
	if (nbr_lo == m->rmv_max + 1) {
		m->line_ai = lone;
		m->matches_ai = m->rmv_max;
		return (1);
	}
	if (nbr_lo == m->rmv_max * 2 + 1) {
		m->line_ai = lone;
		m->matches_ai = m->rmv_max;
		return (1);
	}
	return (0);
}

int check_line_ai_loop_algo1(match_t *m, int j)
{
	for (int i = 0; m->map[j][i] != '\0'; i++) {
		if (m->map[j][i] == '|') {
			return (j);
		}
	}
	return (0);
}

int check_line_ai_algo1(match_t *m)
{
	int line_one = 0;

	for (int j = 0; m->map[j] != NULL && line_one == 0; j++) {
		line_one = check_line_ai_loop_algo1(m, j);
	}
	if (check_size_algo1(m, line_one) == 1)
		return (1);
	else
		return (0);
}
