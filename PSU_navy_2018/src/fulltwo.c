/*
** EPITECH PROJECT, 2019
** aie
** File description:
** aie
*/

#include "../include/my.h"

void suiteseven(int hey)
{
    while (game.a_to <= game.b_to) {
        game.enemy.themap[game.a_from][game.a_to] = hey + '0' - 2;
        game.a_to++;
    }
}

void suiteheight(int hey)
{
    while (game.a_to >= game.b_to) {
        game.enemy.themap[game.a_from][game.a_to] = hey + '0' - 2;
        game.a_to--;
    }
}

void followtwo(int hey)
{
    while (game.a_to >= game.b_to) {
        game.our.themap[game.a_from][game.a_to] = hey + '0' - 2;
        game.a_to--;
    }
}

void suitefive(int hey)
{
    if (game.a_to <= game.b_to)
        suiteseven(hey);
    else
        suiteheight(hey);
}

void suitesix(int hey)
{
    if (game.a_from <= game.b_from)
        suitenine(hey);
    else
        suiteten(hey);
}