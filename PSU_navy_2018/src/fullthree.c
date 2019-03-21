/*
** EPITECH PROJECT, 2019
** aie
** File description:
** aie
*/

#include "../include/my.h"

void suitenine(int hey)
{
    while (game.a_from <= game.b_from) {
        game.enemy.themap[game.a_from][game.a_to] = hey + '0' - 2;
        game.a_from++;
    }
}

void suiteten(int hey)
{
    while (game.a_from >= game.b_from) {
        game.enemy.themap[game.a_from--][game.a_to] = hey + '0' - 2;
        game.a_from--;
    }
}

void followthree(int hey)
{
    while (game.a_from <= game.b_from) {
        game.our.themap[game.a_from][game.a_to] = hey + '0' - 2;
        game.a_from++;
    }
}

void followfour(int hey)
{
    while (game.a_from >= game.b_from) {
        game.our.themap[game.a_from][game.a_to] = hey + '0' - 2;
        game.a_from--;
    }
}