/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** player.c
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"

char *delete_n(char *str)
{
    char *deleted = malloc(sizeof (char) * (my_strlen(str) + 1));

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            return deleted;
        deleted[i] = str[i];
    }
    return NULL;
}

void remove_match(s_t *s, int ls, int ns)
{
    my_putstr("Player removed ");
    my_putnbr(ns);
    my_putstr(" match(es) from line ");
    my_putnbr(ls);
    my_putchar('\n');
    s->row[ls - 1] -= ns;
    print_map(s);
}

void too_many_matches(s_t *s)
{
    my_puterror("Error: you cannot remove more than ");
    my_putnbr(s->matches);
    my_puterror(" matches per turn\n");
    play_input(s);
}

int is_match(int ls, char *str, s_t *s)
{
    int ns = my_getnbr(str);

    str = delete_n(str);
    if (ns == 0) {
        my_puterror("Error: you have to remove at least one match\nLine: ");
        return 84;
    }
    if (ns == 84) {
        my_puterror("Error: invalid input (positive number expected)\nLine: ");
        return 84;
    }
    if (ls == -1)
        return 0;
    if (ns  > s->row[ls - 1]) {
        my_puterror("Error: not enough matches on this line\nLine: ");
        play_input(s);
    } else if (ns < 1 || ns > s->matches)
        too_many_matches(s);
    else
        remove_match(s, ls, ns);
    return 42;
}

int play_input(s_t *s)
{
    size_t bufsize = 32;
    char *str = malloc(sizeof (char) * bufsize);
    int ls;

    if (getline(&str, &bufsize, stdin) == -1)
        return 0;
    str = delete_n(str);
    ls = my_getnbr(str);
    if (ls == 84)
        return norm_saver();
    if (ls < 1 || ls > s->lines) {
        my_puterror("Error: this line is out of range\nLine: ");
        play_input(s);
    } else {
        my_putstr("Matches: ");
        if (getline(&str, &bufsize, stdin) == -1)
            return 0;
        str = delete_n(str);
        return (is_match(ls, str, s));
    }
}