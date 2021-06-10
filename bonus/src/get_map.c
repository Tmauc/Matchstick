/*
** EPITECH PROJECT, 2017
** get_map.c
** File description:
** get_map.c
*/

#include "match.h"

char *edge(char *edge, int width)
{
	for (int i = 0; i != width; i++)
		edge[i] = '*';
	edge[width] = '\0';
	return (edge);
}

void mal_map(match_t *m)
{
	m->map = malloc(sizeof(char *) * (m->height + 1));
	for (int i = 0; i != m->height; i++)
		m->map[i] = my_calloc(sizeof(char) * m->width + 1);
	m->map[m->height] = NULL;
}

void set_middle_map(match_t *m, int j)
{
	m->space = (m->height - 3) - 1 * (j - 1);
	m->nb = 1 + 2 * (j - 1);
	m->map[j][0] = '*';
	for (int i = 1; i != m->width - 1; i++, m->space--) {
		if (m->space <= 0 && m->nb > 0) {
			m->map[j][i] = '|';
			m->nb--;
		} else
			m->map[j][i] = ' ';
	}
	m->map[j][m->width - 1] = '*';
	m->map[j][m->width] = '\0';
}

void get_map(match_t *m)
{
	mal_map(m);
	m->map[0] = edge(m->map[0], m->width);
	for (int j = 1; j != m->height - 1; j++) {
		set_middle_map(m, j);
	}
	m->map[m->height - 1] = edge(m->map[m->height - 1], m->width);
}
