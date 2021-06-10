/*
** EPITECH PROJECT, 2018
** check_buffer.c
** File description:
** check_buffer.c
*/

#include "match.h"

int restart_input_line(match_t *m)
{
	my_free(&m->buf_line);
	my_putstr("Line: ");
	m->buf_line = get_next_line(0);
	if (check_buffer_line(m) == 84)
		return (84);
	return (0);
}

int check_nbr_matches_on_line_fline(match_t *m)
{
	int compter = 0;

	for (int i = 0; m->map[m->line][i] != '\0'; i++)
		if (m->map[m->line][i] == '|')
			compter++;
	if (compter <= 0) {
		my_putstr("Error: not enough matches on this line\n");
		m->return_value = restart_input_line(m);
		return (m->return_value);
	}
	return (0);
}

int check_buffer_line_part2(match_t *m)
{
	if (m->line > (m->height - 2) || m->line == 0) {
		my_putstr("Error: this line is out of range\n");
		m->return_value = restart_input_line(m);
		return (m->return_value);
	}
	if (check_nbr_matches_on_line_fline(m) == 0)
		my_free(&m->buf_line);
	return (m->return_value);
}

int check_buffer_line(match_t *m)
{
	if (m->buf_line == NULL) {
		my_free(&m->buf_line);
		m->ret_val_ctr = 1;
		return (84);
	}
	m->line = str_to_int(m->buf_line);
	for (int i = 0; m->buf_line[i] != '\0'; i++)
		if (m->buf_line[i] < 48 || m->buf_line[i] > 57) {
			my_putstr("Error: invalid input ");
			my_putstr("(positive number expected)\n");
			m->return_value = restart_input_line(m);
			return (m->return_value);
		}
	return (check_buffer_line_part2(m));
}
