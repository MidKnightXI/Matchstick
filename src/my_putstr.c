/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my_putchar.c
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
void my_putechar(char c)
{
    write(2, &c, 1);
}
void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
void my_puterror(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putechar(str[i]);
}