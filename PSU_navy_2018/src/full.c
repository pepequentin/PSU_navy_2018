/*
** EPITECH PROJECT, 2019
** aie
** File description:
** aie
*/

#include "../include/my.h"

void suiteone(int i, int j)
{
    if (game.our.themap[i][j] >= '2' && game.our.themap[i][j] <= '5')
        game.trash = 0;
    else
        game.our.themap[i][j] = '.';
}

void follow(int hey)
{
    while (game.a_to <= game.b_to) {
        game.our.themap[game.a_from][game.a_to] = hey + '0' - 2;
        game.a_to++;
    }
}

void suitetwo(int hey)
{
    if (game.a_to <= game.b_to)
        follow(hey);
    else
        followtwo(hey);
}

void suitethree(int hey)
{
    if (game.a_from <= game.b_from)
        followthree(hey);
    else
        followfour(hey);
}

void suitefour(int i, int j)
{
    if (game.enemy.themap[i][j] >= '2' && game.enemy.themap[i][j] <= '5')
        game.trash = 0;
    else
        game.enemy.themap[i][j] = '.';
}
