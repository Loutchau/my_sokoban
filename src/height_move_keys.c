/*
** EPITECH PROJECT, 2022
** B-PSU-200-MLH-2-1-mysokoban-luca.haumesser
** File description:
** move_keys
*/

#include "../include/my.h"

char *up_move_case_calc(char *buffer, pos_t *player,
int nb_char, int nb_char_beg)
{
    int case_pos = player->pos - nb_char_beg + nb_char;
    int nb_char_case = nb_on_line(buffer, case_pos);
    int nb_char_beg_case = st_char_line(buffer, case_pos, nb_char_case);
    int result = check_space(buffer,
    case_pos - nb_char_beg_case + nb_char_case);

    if (result == 0 || result == 2) {
        buffer[player->pos] = ' ';
        buffer[case_pos] = 'P';
        buffer[case_pos - nb_char_beg_case + nb_char_case] = 'X';
        player->pos = player->pos - nb_char_beg + nb_char;
        return (buffer);
    }
}

int up(char *buffer, pos_t *player, target_case_t *target)
{
    int nb_char = nb_on_line(buffer, player->pos);
    int nb_char_beg = st_char_line(buffer, player->pos, nb_char);
    int result = check_space(buffer, player->pos - nb_char_beg + nb_char);

    if (result == 0) {
        buffer[player->pos] = ' ';
        buffer[player->pos - nb_char_beg + nb_char] = 'P';
        player->pos = player->pos - nb_char_beg + nb_char;
    }
    if (result == 2)
        buffer = up_move_case_calc(buffer, player, nb_char, nb_char_beg);
    return 0;
}

char *down_move_case_calc(char *buffer, pos_t *player,
int nb_char, int nb_char_beg)
{
    int case_pos = player->pos + nb_char_beg + nb_char;
    int nb_char_case = nb_on_line(buffer, case_pos);
    int nb_char_beg_case = nx_char_line(buffer, case_pos, nb_char_case);
    int result = check_space(buffer, case_pos + nb_char_beg + nb_char);

    if (result == 0) {
        buffer[player->pos] = ' ';
        buffer[case_pos] = 'P';
        buffer[case_pos + nb_char_beg_case + nb_char_case] = 'X';
        player->pos = case_pos;
        return (buffer);
    }
}

int down(char *buffer, pos_t *player, target_case_t *target)
{
    int nb_char = nb_on_line(buffer, player->pos);
    int nb_char_beg = nx_char_line(buffer, player->pos, nb_char);
    int result = check_space(buffer, player->pos + nb_char_beg + nb_char);

    if (result == 0) {
        buffer[player->pos] = ' ';
        buffer[player->pos + nb_char_beg + nb_char] = 'P';
        player->pos = player->pos + nb_char_beg + nb_char;
    }
    if (result == 2)
        buffer = down_move_case_calc(buffer, player, nb_char, nb_char_beg);
    return 0;
}
