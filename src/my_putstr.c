/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my_putchar.c
*/
#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_puterror(char *str)
{
    write(2, str, my_strlen(str));
}