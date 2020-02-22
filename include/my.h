/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my
*/
#include "struct.h"

#ifndef MY_H_
#define MY_H_

void my_putchar(char c);
int my_strlen(char *str);
void my_putstr(char *str);
void my_puterror(char *str);
void my_putchars(int i, char c);
int norm_saver(void);
int my_getnbr(char *str);
void my_putnbr(int nb);
void print_map(s_t *s);
int play_ai(s_t *s, int i);
int play_input(s_t *s);
int play_game(s_t *s);

#endif /* !MY_H_ */