/*
** EPITECH PROJECT, 2018
** prog.c
** File description:
** prog.c
*/

#include "match.h"

void print_bonus_str(match_t *m)
{
	my_putstr("Round ");
	my_put_nbr(m->nbr_match);
	my_putchar('\n');
	my_putstr("AI's win(");
	my_put_nbr(m->nbr_win_ai);
	my_putstr("), Player's win(");
	my_put_nbr(m->nbr_win_player);
	my_putstr(")\n");
}

void restart_or_no(match_t *m)
{
	char *buffer = NULL;

	my_putstr("Do you want a revenge? (yes, no)\n");
	buffer = get_next_line(0);
	if (buffer == NULL)
		return;
	if (my_strcmp(buffer, "yes") == 0) {
		free(buffer);
		m->restart = 1;
		my_putstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		my_putstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		my_putstr("Let's do it!!\n");
	} else if (my_strcmp(buffer, "no") == 0) {
		free(buffer);
		m->restart = 0;
		my_putstr("Okay, maybe next time :'(\n");
	} else {
		free(buffer);
		restart_or_no(m);
	}
}

int player_turn(match_t *m)
{
	my_putstr("Your turn (");
	my_put_nbr(m->nbr_turn);
	my_putstr("):\n");
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

int check_restart_finish(match_t *m, char **av, int return_value)
{
	if (return_value != 1)
		restart_or_no(m);
	free_struct(m);
	if (m->restart == 1) {
		setup(m, av);
		prog(m, av);
	}
	if (m->ret_val_ctr == 1)
		m->return_value = 0;
	return (m->return_value);
}

int prog(match_t *m, char **av)
{
	int return_value = 0;

	print_bonus_str(m);
	while (m->nbr_matches > 0) {
		print_map(m);
		if (player_turn(m) == 84) {
			return_value = 1;
			break;
		} if (m->nbr_matches > 0) {
			print_map(m);
			ai_turn(m);
		}
		m->nbr_turn++;
	}
	return (check_restart_finish(m, av, return_value));
}
