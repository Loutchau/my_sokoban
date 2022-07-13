/*
** EPITECH PROJECT, 2022
** B-PSU-200-MLH-2-1-mysokoban-luca.haumesser
** File description:
** move
*/

#include "../include/my.h"

int check_space(char *buffer, int verif)
{
    if (buffer[verif] == ' ')
        return 0;
    if (buffer[verif] == 'O')
        return 0;
    if (buffer[verif] == '#')
        return 1;
    if (buffer[verif] == 'X')
        return 2;
}

int nb_on_line(char *buffer, int pos)
{
    int i = 0;

    for (; buffer[pos - i] != '\n'; ++i);
    return (i - 2);
}

int st_char_line(char *buffer, int pos, int nb_char)
{
    int i = 0;
    int nbr_of_line = 0;
    int st_line = 0;

    for (; buffer[st_line] != '\n'; ++st_line);
    for (; pos > i; ++i) {
        if (buffer[pos - i] == '\n' && nbr_of_line == 1)
            return (i - 2);
        if (buffer[pos - i] == '\n' && nbr_of_line == 0)
            ++nbr_of_line;
    }
    return (i);
}

int nx_char_line(char *buffer, int pos, int nb_char)
{
    int i = 0;
    int nbr_of_line = 0;
    int nx_line = 0;

    for (; buffer[pos + i] != '\n'; ++i);
    return (i + 2);
}
