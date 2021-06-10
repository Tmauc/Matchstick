/*
** EPITECH PROJECT, 2017
** print_map.c
** File description:
** print_map.c
*/

#include "match.h"

void print_map_win(match_t *m)
{
	for (int i = 0; m->map[i] != NULL; i++) {
		my_putstr(m->map[i]);
		my_putchar('\n');
	}
	my_putstr("I lost... snif... but I'll get you next time!!\n");
}

void print_map_loos(match_t *m)
{
	for (int i = 0; m->map[i] != NULL; i++) {
		my_putstr(m->map[i]);
		my_putchar('\n');
	}
	my_putstr("You lost, too bad...\n");
}

void print_map(match_t *m)
{
	for (int i = 0; m->map[i] != NULL; i++) {
		my_putstr(m->map[i]);
		my_putchar('\n');
	}
	my_putchar('\n');
}
