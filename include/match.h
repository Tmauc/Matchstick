/*
** EPITECH PROJECT, 2018
** match.h
** File description:
** match.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "struct.h"
#include "time.h"
#include "my.h"

#ifndef MATCH_H
#define MATCH_H

#ifndef READ_SIZE
#define READ_SIZE (1)
#endif

int prog(match_t *m);

int check_error(char **av);
int check_buffer_line(match_t *m);
int check_buffer_matches(match_t *m);
int check_line_ai(match_t *m);

void setup(match_t *m, char **av);

void get_map(match_t *m);
void print_map(match_t *m);
void print_map_loos(match_t *m);
void print_map_win(match_t *m);

void my_free(void *temp);
void free_struct(match_t *m);

int remove_matches_player(match_t *m);

void ai_turn(match_t *m);
void algo_ia(match_t *m);

int compt_line(match_t *m);
int get_nbr_matches_ia(match_t *m, int line);
int check_line_ai_algo1(match_t *m);
int remove_max_matches(match_t *m);

#endif
