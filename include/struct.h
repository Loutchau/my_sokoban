/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct pos_s {
    int pos;
} pos_t;

typedef struct target_case_s {
    int nbr_pos;
    int *pos;
    int nbr_case;
} target_case_t;

typedef struct reset_s {
    int player_pos;
    char *buffer;
} reset_t;

#endif /* !STRUCT_H_ */
