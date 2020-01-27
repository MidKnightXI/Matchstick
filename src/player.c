/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** player.c
*/
#include <stdlib.h>
#include <stdio.h>
#include "../include/struct.h"

char *delete_n(char *str)
{
    char *deleted = malloc(sizeof (char) * (my_strlen(str) + 1));

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            return deleted;
        deleted[i] = str[i];
    }
}
int is_match(int ls, char *str, s_t *s)
{
    int ns = my_getnbr(str);

    if (ns == 0) {
        my_putstr("Error: you have to remove at least one match\nLine: ");
        return 84;
    }
    if (my_getnbr(str) == 84) {
        my_putstr("Error: invalid input (positive number expected)\n");
        my_putstr("Line: ");
        return 84;
    }
    if (ls == -1)
        return 0;
    if (ns  > s->row[ls - 1]) {
        my_putstr("Error: not enough matches on this line\n");
        play_input(s);
    } else if (ns < 1 || ns > s->matches) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(s->matches);
        my_putstr(" matches per turn\n");
        play_input(s);
    } else {
        my_putstr("Player removed ");
        my_putnbr(ns);
        my_putstr(" match(es) from line ");
        my_putnbr(ls);
        my_putchar('\n');
        s->row[ls - 1] -= ns;
        print_map(s);
    }
}
int play_input(s_t *s)
{
    size_t bufsize = 32;
    size_t characters;
    char *str = malloc(sizeof (char) * bufsize);
    int ls;

    if (getline(&str, &bufsize, stdin) == -1)
        return 0;
    str = delete_n(str);
    ls = my_getnbr(str);
    if (my_getnbr(str) == 84) {
        my_putstr("Error: invalid input (positive number expected)\n");
        my_putstr("Line: ");
        return 84;
    }
    if (ls < 1 || ls > s->lines) {
        my_putstr("Error: this line is out of range\n");
        play_input(s);
    } else {
        my_putstr("Matches: ");
        getline(&str, &bufsize, stdin);
        str = delete_n(str);
        return (is_match(ls, str, s));
    }
}