/*
** EPITECH PROJECT, 2019
** aie
** File description:
** aie
*/

#include "../include/my.h"

int put_error(void)
{
    write(2, "Map error\n", 11);
    return (84);
}