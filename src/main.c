/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** main.c
*/
#include "my.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

int init_int(s_t *s, int i)
{
    if (i == 0) {
        return 1;
    } else {
        return (s->row[i - 1] + 2);
    }
}

void attribute_values(char **av, s_t *s)
{
    s->lines = my_getnbr(av[1]);
    s->matches = my_getnbr(av[2]);
    s->width = 1 + (2 * (s->lines - 1));
    s->row = malloc(sizeof (int) * s->lines);

    for (int i = 0; i < s->lines; i++) {
        s->row[i] = init_int(s, i);
    }
}

int check_error(s_t *s)
{
    if (s->lines <= 1 || s->lines > 100)
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    s_t *s = malloc(sizeof (s_t));
    int exit = 0;

    if (ac > 3 || ac < 3)
        return 84;
    attribute_values(av, s);
    if (check_error(s) == 84)
        return 84;
    print_map(s);
    exit = play_game(s);
    if (exit == 0)
        return 0;
    else if (exit == 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return 1;
    } else if (exit == 2) {
        my_putstr("You lost, too bad...\n");
        return 2;
    }
}