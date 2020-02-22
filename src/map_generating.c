/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** map_generating.c
*/
#include "my.h"
#include "struct.h"
#include <stdlib.h>

void display_stars(s_t *s)
{
    for (int i = 0; i < (s->width + 2); i++)
        my_putchar('*');
    my_putchar('\n');
}
void print_map(s_t *s)
{
    int len = s->lines;
    int i = 0;

    display_stars(s);
    for (int j = 0; j != len; j++, i++) {
        my_putchar('*');
        my_putchars(len - 1 - i, ' ');
        my_putchars(s->row[j], '|');
        my_putchars(((len * 2 - 1) - (len - 1 - i)) - s->row[j], ' ');
        my_putchar('*');
        my_putchar('\n');
    }
    display_stars(s);
    my_putchar('\n');
}