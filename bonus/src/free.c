/*
** EPITECH PROJECT, 2018
** free.c
** File description:
** free.c
*/

#include "match.h"

void my_free(void *temp)
{
	void **str = (void **)temp;
	if (*str != NULL) {
		free(*str);
		*str = NULL;
	}
}

void free_struct(match_t *m)
{
	if (m->map == NULL)
		return;
	for (int i = 0; m->map[i] != NULL; i++)
		free(m->map[i]);
	free(m->map);
}
