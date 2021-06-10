/*
** EPITECH PROJECT, 2018
** ai_fcnts.c
** File description:
** ai_fcnts.c
*/

#include "match.h"

int remove_matches_ia(match_t *m)
{
	for (int i = m->width; i != 0 && m->matches_ai != 0; i--)
		if (m->map[m->line_ai][i] == '|') {
			m->map[m->line_ai][i] = ' ';
			m->matches_ai -= 1;
			m->nbr_matches -= 1;
		}
	if (m->nbr_matches <= 0) {
		print_map_win(m);
		return (1);
	} else
		return (0);
}

int get_matches_ia(match_t *m)
{
	int compter = 0;

	for (int i = 0; m->map[m->line_ai][i] != '\0'; i++) {
		if (m->map[m->line_ai][i] == '|')
			compter++;
	}
	if (compter >= m->rmv_max)
		return (m->rmv_max);
	else if (compter >= m->rmv_max)
		return (compter);
	else
		return (1);
}

void check_nbr_matches_on_line_ai(match_t *m)
{
	int compter = 0;

	for (int i = 0; m->map[m->line_ai][i] != '\0'; i++)
		if (m->map[m->line_ai][i] == '|')
			compter++;
	if (compter <= 0)
		algo_ia(m);
}

void algo_ia(match_t *m)
{
	int bol = 0;
	int nbr_line = compt_line(m);

	if (nbr_line == 2)
		bol = check_line_ai(m);
	if (nbr_line == 1)
		bol = check_line_ai_algo1(m);
	if (bol == 0) {
		m->line_ai = rand() % (m->height - 1) + 1;
		check_nbr_matches_on_line_ai(m);
		m->matches_ai = rand() % (get_matches_ia(m)) + 1;
	}
	if (m->matches_ai == 0)
		m->matches_ai = 1;
}

void ai_turn(match_t *m)
{
	my_putstr("AI's turn...\n");
	algo_ia(m);
	my_putstr("AI removed ");
	my_put_nbr(m->matches_ai);
	my_putstr(" match(es) from line ");
	my_put_nbr(m->line_ai);
	my_putchar('\n');
	m->return_value = remove_matches_ia(m);
}
