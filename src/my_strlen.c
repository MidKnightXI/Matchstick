/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int len = 0;

    for (; str[len]; len++);
    return (len);
}