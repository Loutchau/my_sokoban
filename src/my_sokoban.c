/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** my_sokoban
*/

#include "../include/my.h"

int check_loose(char *map, target_case_t *target)
{
    int result = 0;

    for (int i = 0; map[i] != '\0'; ++i) {
        if (map[i] == 'X')
            result += check_corner(map, i);
    }
    if (result == target->nbr_case)
        return 1;
    return 0;
}

int check_finish(char *buffer, target_case_t *target)
{
    if (0 == check_win(buffer, target)) {
        mvprintw(0, 0, buffer);
        refresh();
        usleep(100000);
        exit(0);
    }
    if (1 == check_loose(buffer, target)) {
        mvprintw(0, 0, buffer);
        refresh();
        usleep(100000);
        exit(1);
    }
}

int sokoban(char const *map, target_case_t *target, pos_t *player,
            reset_t *reset)
{
    char *buffer = f_map(map);
    int key_nbr = 0;
    int i = 0;

    setup_target_reset(buffer, target, player, reset);
    while (1) {
        refresh();
        check_finish(buffer, target);
        mvprintw(0, 0, buffer);
        key_nbr = getch();
        if (key_nbr == 32)
            buffer = reset_f(reset, player, buffer);
        key_press(buffer, player, target, key_nbr);
        buffer = replace_target(buffer, target);
        clear();
    }
    return 0;
}

int invalid_char(char *map)
{
    for (int i = 0; map[i] != '\0'; ++i)
        if (map[i] != '#' && map[i] != ' ' && map[i] != '\n' && map[i] != 'P' &&
            map[i] != 'X' && map[i] != 'O')
            exit(84);
    return 0;
}

int main(int argc, char const *argv[])
{
    char *buffer = f_map(argv[1]);
    target_case_t target;
    pos_t player;
    reset_t reset;

    if (argv[1] != NULL && argv[1][0] == '-' && argv[1][1] == 'h')
        flag_h();
    if (1 == invalid_char(buffer))
        return 84;
    initscr();
    curs_set(FALSE);
    mvprintw(0, 0, buffer);
    refresh();
    target.nbr_case = nbr_case_f(buffer);
    sokoban(argv[1], &target, &player, &reset);
    endwin();
    return 0;
}
