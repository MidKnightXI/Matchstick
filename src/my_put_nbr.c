/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_put_nbr
*/
#include <unistd.h>

void my_putnbr(int nb)
{
    int dc = 1;

    if (nb == -2147483648)
        write(1, "-2147483648", 12);
    else {
        if (nb < 0) {
	        my_putchar('-');
	        nb = nb * -1;
	    }
        while ((nb / dc) >= 10) {
            dc = dc * 10;
        }
        while (dc > 0) {
	        my_putchar((nb / dc) % 10 + '0');
	        dc /= 10;
        }
    }
}
