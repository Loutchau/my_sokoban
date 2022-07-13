/*
** EPITECH PROJECT, 2022
** B-PSU-200-MLH-2-1-mysokoban-luca.haumesser
** File description:
** loose_condition
*/

#include "../include/my.h"

int check_top(char *map, int case_pos)
{
    int nb_char = nb_on_line(map, case_pos);
    int nb_char_beg = st_char_line(map, case_pos, nb_char);
    int result = check_space(map, case_pos - nb_char_beg + nb_char);

    if (result == 1)
        return 1;
    return 0;
}

int check_right(char *map, int case_pos)
{
    if (map[case_pos + 1] == '#')
        return 1;
    return 0;
}

int check_bot(char *map, int case_pos)
{
    int nb_char = nb_on_line(map, case_pos);
    int nb_char_beg = nx_char_line(map, case_pos, nb_char);
    int result = check_space(map, case_pos + nb_char_beg + nb_char);

    if (result == 1)
        return 1;
    return 0;
}

int check_left(char *map, int case_pos)
{
    if (map[case_pos - 1] == '#')
        return 1;
    return 0;
}

int check_corner(char *map, int pos_case)
{
    if (1 == check_top(map, pos_case) && 1 == check_right(map, pos_case))
        return 1;
    if (1 == check_right(map, pos_case) && 1 == check_bot(map, pos_case))
        return 1;
    if (1 == check_bot(map, pos_case) && 1 == check_left(map, pos_case))
        return 1;
    if (1 == check_left(map, pos_case) && 1 == check_top(map, pos_case))
        return 1;
    return 0;
}
