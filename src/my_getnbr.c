/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my_getnumber.c
*/
#include "../include/struct.h"

int my_getnbr(char *str)
{
    int i = 0;
    int num = 0;

    if (str[0] == '-' && str[1] != '\0')
        i++;
    for (;str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 84;
        num = num + (str[i] - 48);
        num = num * 10;
    }
    num /= 10;
    if (str[0] == '-')
        return (-1 * num);
    else
        return num;
}