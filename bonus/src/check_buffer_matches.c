/*
** EPITECH PROJECT, 2018
** check_buffer.c
** File description:
** check_buffer.c
*/

#include "match.h"

int restart_input_matches(match_t *m)
{
	if (m->buf_matches != NULL)
		my_free(&m->buf_matches);
	my_putstr("Line: ");
	m->buf_line = get_next_line(0);
	if (check_buffer_line(m) == 84)
		return (84);
	my_putstr("Matches: ");
	m->buf_matches = get_next_line(0);
	if (check_buffer_matches(m) == 84) {
		return (84);
	}
	return (0);
}

int check_nbr_matches_on_line_fmatches(match_t *m)
{
	int compter = 0;

	for (int i = 0; m->map[m->line][i] != '\0'; i++)
		if (m->map[m->line][i] == '|')
			compter++;
	if (compter < m->matches) {
		my_putstr("Error: not enough matches on this line\n");
		m->return_value = restart_input_matches(m);
		return (m->return_value);
	}
	return (0);
}

int check_buffer_matches_part2(match_t *m)
{
	if (m->matches == 0) {
		my_putstr("Error: you have to remove at least one match\n");
		m->return_value = restart_input_matches(m);
		return (m->return_value);
	} else if (m->matches > m->rmv_max) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(m->rmv_max);
		my_putstr(" matches per turn\n");
		m->return_value = restart_input_matches(m);
		return (m->return_value);
	}
	return (0);
}

int check_buffer_matches(match_t *m)
{
	if (m->buf_matches == NULL) {
		my_free(&m->buf_matches);
		my_free(&m->buf_line);
		m->ret_val_ctr = 1;
		return (84);
	}
	m->matches = str_to_int(m->buf_matches);
	for (int i = 0; m->buf_matches[i] != '\0'; i++)
		if (m->buf_matches[i] < 48 || m->buf_matches[i] > 57) {
			my_putstr("Error: invalid input ");
			my_putstr("(positive number expected)\n");
			m->return_value = restart_input_matches(m);
			return (m->return_value);
		}
	if (check_buffer_matches_part2(m) == 84) {
		return (84);
	}
	m->return_value = check_nbr_matches_on_line_fmatches(m);
	my_free(&m->buf_matches);
	return (m->return_value);
}
