/*
** EPITECH PROJECT, 2022
** B-PSU-200-MLH-2-1-mysokoban-luca.haumesser
** File description:
** replace_target
*/

#include "../include/my.h"

char *replace_target(char *buffer, target_case_t *target)
{
    for (int i = 0; i < target->nbr_pos; ++i)
        if (buffer[target->pos[i]] == ' ')
            buffer[target->pos[i]] = 'O';
    return (buffer);
}

int check_win(char *buffer, target_case_t *target)
{
    for (int i = 0; i < target->nbr_pos; ++i)
        if (buffer[target->pos[i]] != 'X')
            return 1;
    return 0;
}
