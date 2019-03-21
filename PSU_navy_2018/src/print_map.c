/*
** EPITECH PROJECT, 2019
** print_map.c
** File description:
** lol
*/

#include "../include/my.h"

void print_map_our(void)
{
    my_printf("%s\n%s\n", game.letters, game.tir);
    for (int i = 0; i != 8; i++) {
    my_printf("%d|", i + 1);
        for (int j = 0; j!= 8; j++)
            my_printf("%c ", game.our.themap[i][j]);
    my_printf("\n");
    }
}

void print_map_enemy(void)
{
    my_printf("%s\n%s\n", game.letters, game.tir);
    for (int i = 0; i != 8; i++) {
    my_printf("%d|", i + 1);
        for (int j = 0; j!= 8; j++)
            my_printf("%c ", game.enemy.themap[i][j]);
    my_printf("\n");
    }
}

void print_map_vide_our(void)
{
    my_printf("\n%s\n%s\n", game.letters, game.tir);
    for (int i = 0; i != 8; i++) {
    my_printf("%d|", i + 1);
        for (int j = 0; j!= 8; j++)
            my_printf("%c ", game.our.voidmap[i][j]);
    my_printf("\n");
    }
}

void print_map_vide_client(void)
{
    my_printf("\n%s\n%s\n", game.letters, game.tir);
    for (int i = 0; i != 8; i++) {
    my_printf("%d|", i + 1);
        for (int j = 0; j!= 8; j++)
            my_printf("%c ", game.enemy.voidmap[i][j]);
    my_printf("\n");
    }
}