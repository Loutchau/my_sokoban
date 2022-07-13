/*
** EPITECH PROJECT, 2022
** B-PSU-200-MLH-2-1-mysokoban-luca.haumesser
** File description:
** target_reset
*/

#include "../include/my.h"

int find_player(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; ++i)
        if (buffer[i] == 'P')
            return (i);
}

int nbr_of_target(char *buffer)
{
    int result = 0;

    for (int i = 0; buffer[i] != '\0'; ++i)
        if (buffer[i] == 'O')
            ++result;
    return (result);
}

int pos_target(char *buffer, target_case_t *target)
{
    int nbr_of_target = 0;

    for (int i = 0; buffer[i] != '\0'; ++i)
        if (buffer[i] == 'O') {
            target->pos[nbr_of_target] = i;
            ++nbr_of_target;
        }
}

void setup_target_reset(char *buffer, target_case_t *target,
pos_t *player, reset_t *reset)
{
    int nbr_char = 0;

    target->nbr_pos = nbr_of_target(buffer);
    target->pos = malloc(sizeof(int) * (target->nbr_pos));
    pos_target(buffer, target);
    player->pos = find_player(buffer);
    reset->player_pos = player->pos;
    for (; buffer[nbr_char] != '\0'; ++nbr_char);
    reset->buffer = malloc(nbr_char);
    for (int i = 0; buffer[i] != '\0'; ++i)
        reset->buffer[i] = buffer[i];
}

char *reset_f(reset_t *reset, pos_t *player, char *buffer)
{
    player->pos = reset->player_pos;
    for (int i = 0; reset->buffer[i] != '\0'; ++i)
        buffer[i] = reset->buffer[i];
    return (buffer);
}
