/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** my_putstr
*/
#include "my.h"

int my_putstr(char const *str)
{
    long long int run;
    run = 0;
    while (str[run] == '0') {
        run++;
    }
    while (str[run] != '\0'){
        my_putchar(str[run]);
        run++;
    }
}