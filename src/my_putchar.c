/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my_putchar.c
*/

#include <unistd.h>

void my_putchars(int i, char c)
{
    for (int j = 0; j != i; j++) {
        write(1, &c, 1);
    }
}