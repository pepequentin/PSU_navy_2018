/*
** EPITECH PROJECT, 2019
** aie
** File description:
** aie
*/

#include "../include/my.h"

void hitedornot(int i, int j)
{
    if (game.enemy.themap[j - 1][i - 1] != '.'&& \
        game.enemy.themap[j - 1][i - 1] != 'o' && \
        game.enemy.themap[j - 1][i - 1] != 'x') {
        game.enemy.themap[j - 1][i - 1] = 'x';
        kill(game.our.pid, SIGUSR1);
        usleep(5000);
    }
    else {
        kill(game.our.pid, SIGUSR1);
        usleep(5000);
        kill(game.our.pid, SIGUSR1);
        usleep(5000);
        game.enemy.themap[j - 1][i - 1] = 'o';
    }
    kill(game.our.pid, SIGUSR2);
    usleep(5000);
}

void defence_client(void)
{
    int i;
    int j;

    for (game.var_glob = 0; game.var_glob == 0;)
        game.trash = 0;
    i = game.var_glob;
    for (game.var_glob = 0; game.var_glob == 0;)
        game.trash = 0;
    j = game.var_glob;
    my_printf("%c%c: ", i + 'A' - 1, j + '0');
    if (game.enemy.themap[j - 1][i - 1] != '.' && \
        game.enemy.themap[j - 1][i - 1] != 'o' && \
        game.enemy.themap[j - 1][i - 1] != 'x')
        my_printf("hit\n");
    else
        my_printf("missed\n");
    hitedornot(i, j);
}

void hitedornotserv(int i, int j)
{
    if (game.our.themap[j - 1][i - 1] != '.') {
        game.our.themap[j - 1][i - 1] = 'x';
        kill(game.enemy.pid, SIGUSR1);
        usleep(5000);
    }
    else {
        kill(game.enemy.pid, SIGUSR1);
        usleep(5000);
        kill(game.enemy.pid, SIGUSR1);
        usleep(5000);
        game.our.themap[j - 1][i - 1] = 'o';
    }
    kill(game.enemy.pid, SIGUSR2);
    usleep(5000);
}

void defence_serv(void)
{
    int i;
    int j;
    my_printf("\nwaiting for enemy's attack...\n");
    for (game.var_glob = 0; game.var_glob == 0;)
        game.trash = 0;
    i = game.var_glob;
    for (game.var_glob = 0; game.var_glob == 0;)
        game.trash = 0;
    j = game.var_glob;
    my_printf("%c%c: ", i + 'A' - 1, j + '0');
    if (game.our.themap[j - 1][i - 1] != '.')
        my_printf("hit\n");
    else
        my_printf("missed\n");
    hitedornotserv(i, j);
}