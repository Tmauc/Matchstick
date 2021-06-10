/*
** EPITECH PROJECT, 2018
** compt_line.c
** File description:
** compt_line.c
*/

#include "match.h"

int check_size(match_t *m, int lone, int lt)
{
	int nbr_lo = get_nbr_matches_ia(m, lone);
	int nbr_lt = get_nbr_matches_ia(m, lt);

	if (nbr_lo == 1 && nbr_lt <= m->rmv_max) {
		m->line_ai = lt;
		m->matches_ai = nbr_lt;
		return (1);
	} else if (nbr_lt == 1 && nbr_lo <= m->rmv_max) {
		m->line_ai = lone;
		m->matches_ai = nbr_lo;
		return (1);
	}
	return (0);
}

int check_line_ai_loop(match_t *m, int j, int lone)
{
	for (int i = 0; m->map[j][i] != '\0'; i++) {
		if (m->map[j][i] == '|' && j != lone) {
			return (j);
		}
	}
	return (0);
}

int check_line_ai(match_t *m)
{
	int line_one = 0;
	int line_two = 0;

	for (int j = 0; m->map[j] != NULL && line_one == 0; j++) {
		line_one = check_line_ai_loop(m, j, line_one);
	}
	for (int j = 0; m->map[j] != NULL && line_two == 0; j++) {
		line_two = check_line_ai_loop(m, j, line_one);
	}
	if (check_size(m, line_one, line_two) == 1)
		return (1);
	else
		return (0);
}

int compt_line_part2(match_t *m, int i, int compter)
{
	for (int j = 0; m->map[i][j] != '\0'; j++) {
		if (m->map[i][j] == '|') {
			compter++;
			break;
		}
	}
	return (compter);
}

int compt_line(match_t *m)
{
	int compter = 0;

	for (int i = 0; m->map[i] != NULL; i++) {
		compter = compt_line_part2(m, i, compter);
	}
	return (compter);
}
