/*
** EPITECH PROJECT, 2018
** prog.c
** File description:
** prog.c
*/

#include "match.h"

int player_turn(match_t *m)
{
	my_putstr("Your turn:\n");
	my_putstr("Line: ");
	m->buf_line = get_next_line(0);
	if (check_buffer_line(m) == 84)
		return (84);
	my_putstr("Matches: ");
	m->buf_matches = get_next_line(0);
	if (check_buffer_matches(m) == 84)
		return (84);
	if (remove_matches_player(m) == 2)
		m->return_value = 2;
	return (0);
}

int prog(match_t *m)
{
	while (m->nbr_matches > 0) {
		print_map(m);
		if (player_turn(m) == 84)
			break;
		if (m->nbr_matches > 0) {
			print_map(m);
			ai_turn(m);
		}
	}
	free_struct(m);
	if (m->ret_val_ctr == 1)
		m->return_value = 0;
	return (m->return_value);
}
