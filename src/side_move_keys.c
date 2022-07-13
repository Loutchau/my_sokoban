/*
** EPITECH PROJECT, 2022
** B-PSU-200-MLH-2-1-mysokoban-luca.haumesser
** File description:
** move_keys
*/

#include "../include/my.h"

char *side_move_case_calc(char *buffer, pos_t *player, int move)
{
    int result = check_space(buffer, player->pos + (move * 2));

    if (result == 0) {
        buffer[player->pos] = ' ';
        buffer[player->pos + move] = 'P';
        buffer[player->pos + (move * 2)] = 'X';
        player->pos += move;
        return (buffer);
    }
}

int right(char *buffer, pos_t *player, target_case_t *target)
{
    int result = 0;

    result = check_space(buffer, player->pos + 1);
    if (result == 0) {
        buffer[player->pos] = ' ';
        buffer[player->pos + 1] = 'P';
        player->pos += 1;
    }
    if (result == 2)
        buffer = side_move_case_calc(buffer, player, 1);
    return 0;
}

int left(char *buffer, pos_t *player, target_case_t *target)
{
    int result = 0;

    result = check_space(buffer, player->pos - 1);
    if (result == 0) {
        buffer[player->pos] = ' ';
        buffer[player->pos - 1] = 'P';
        player->pos -= 1;
    }
    if (result == 2)
        buffer = side_move_case_calc(buffer, player, -1);
    return 0;
}

int key_press(char *buffer, pos_t *player, target_case_t *target, int key_nbr)
{
    switch (key_nbr) {
    case (65):
        up(buffer, player, target);
        break;
    case (66):
        down(buffer, player, target);
        break;
    case (67):
        right(buffer, player, target);
        break;
    case (68):
        left(buffer, player, target);
        break;
    default:
        return 0;
    }
    return 0;
}
