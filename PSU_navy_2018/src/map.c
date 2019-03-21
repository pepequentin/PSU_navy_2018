/*
** EPITECH PROJECT, 2019
** aie
** File description:
** aie
*/

#include "../include/my.h"

void fullemptymap(void)
{
    for (int i = 0; i != 8; i++)
        for (int j = 0; j != 8; j++) {
            game.enemy.voidmap[i][j] = '.';
            game.our.voidmap[i][j] = '.';
        }
}

void my_allocmap(void)
{
    game.our.themap = malloc(sizeof(char *) * 8);
    game.our.voidmap = malloc(sizeof(char *) * 8);
    game.enemy.themap = malloc(sizeof(char *) * 8);
    game.enemy.voidmap = malloc(sizeof(char *) * 8);

    for (int i = 0; i != 9; i++) {
        game.our.themap[i] = malloc(sizeof(char) + 8);
        game.enemy.themap[i] = malloc(sizeof(char) + 8);
        game.our.voidmap[i] = malloc(sizeof(char) + 8);
        game.enemy.voidmap[i] = malloc(sizeof(char) + 8);
    }
    game.letters = " |A B C D E F G H";
    game.tir = "-+---------------";
    fullemptymap();
}