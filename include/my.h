/*
** EPITECH PROJECT, 2022
** B-PSU-200-MLH-2-1-mysokoban-luca.haumesser
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include "struct.h"
    #include <ncurses.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>

char *f_map(char const *map);
int check_space(char *buffer, int verif);
int nb_on_line(char *buffer, int pos);
int st_char_line(char *buffer, int pos, int nb_char);
int nx_char_line(char *buffer, int pos, int nb_char);
int key_press(char *buffer, pos_t *player, target_case_t *target, int key_nbr);
int up(char *buffer, pos_t *player, target_case_t *target);
int down(char *buffer, pos_t *player, target_case_t *target);
char *replace_target(char *buffer, target_case_t *target);
int check_win(char *buffer, target_case_t *target);
void flag_h(void);
int nbr_of_target(char *buffer);
int pos_target(char *buffer, target_case_t *target);
void setup_target_reset(char *buffer, target_case_t *target,
pos_t *player, reset_t *reset);
char *reset_f(reset_t *reset, pos_t *player, char *buffer);
int sokoban(char const *map, target_case_t *target, pos_t *player,
reset_t *reset);
int check_loose(char *map, target_case_t *target);
int check_corner(char *map, int pos_case);
int nbr_case_f(char *buffer);

#endif /* !MY_H_ */
