/*
** EPITECH PROJECT, 2019
** my_get_nbr.c
** File description:
** lol
*/

#include "../include/my.h"

int my_get_nbr(char *str)
{
    int j = 0;
    int jo = 1;

    if (str[0] == '-')
        jo = -1;
    for (int i = 0; str[i] >= '0' && str[i] <= '9'; i++)
        j = j * 10 + (str[i] - 48);
    return (j * jo);
}