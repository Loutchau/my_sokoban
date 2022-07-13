/*
** EPITECH PROJECT, 2022
** B-PSU-200-MLH-2-1-mysokoban-luca.haumesser
** File description:
** print
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        ++i;
    write(1, str, i);
}

void flag_h(void)
{
    my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\
    map  file representing the warehouse map, containing '#' for walls,\n\
        'P' for the player, 'X' for boxes and 'O' for storage locations.\n");
}
