/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** AI.c
*/
#include "../include/struct.h"

int play_AI(s_t *s, int i)
{
    if (s->row[i] > 0) {
        s->row[i] -= 1;
        my_putstr("AI removed 1 match(es) from line ");
        my_putnbr(i);
        my_putchar('\n');
        print_map(s);
    } else {
        play_AI(s, (i + 1));
    }
   return 0;
}