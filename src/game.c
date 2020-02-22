/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** player.c
*/
#include "my.h"
#include "struct.h"

int check_row(s_t *s)
{
    int i = 0;

    for (int n = 0; n < s->lines; n++) {
        if (s->row[n] == 0)
            i++;
    }
    if (i == s->lines)
        return 1;
    else {
        return 0;
    }
}
int play_game(s_t *s)
{
    int i;

    while (1) {
        my_putstr("Your turn:\nLine: ");
        i = play_input(s);
        if (i == 84)
            play_input(s);
        if (i == 0)
            return 0;
        if (check_row(s) == 1)
            return 2;
        else {
            my_putstr("AI's turn...\n");
            play_ai(s, 0);
            if (check_row(s) == 1)
                return 1;
        }
    }
}
