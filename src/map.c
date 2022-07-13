/*
** EPITECH PROJECT, 2022
** B-PSU-200-MLH-2-1-mysokoban-luca.haumesser
** File description:
** map
*/

#include "../include/my.h"

int nbr_case_f(char *buffer)
{
    int nbr_case = 0;

    for (int i = 0; buffer[i] != '\0'; ++i)
        if (buffer[i] == 'O')
            ++nbr_case;
    return (nbr_case);
}

char *f_map(char const *map)
{
    int size = 0;
    char *buffer;
    int op = 0;
    int rd = 0;
    struct stat file;

    stat(map, &file);
    size = file.st_size;
    buffer = malloc(size + 1);
    op = open(map, O_RDONLY);
    rd = read(op, buffer, size);
    if (op == -1 || rd == -1)
        return ("error");
    size[buffer] = 0;
    return (buffer);
}
