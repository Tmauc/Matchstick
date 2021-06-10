/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_match
{
	char **map;
	char *buf_line;
	char *buf_matches;
	int height;
	int width;
	int nbr_matches;
	int rmv_max;
	int space;
	int nb;
	int return_value;
	int line;
	int matches;
	int line_ai;
	int matches_ai;
	int ret_val_ctr;
	int nbr_turn;
	int restart;
	int nbr_match;
	int nbr_win_ai;
	int nbr_win_player;
} match_t;

#endif
