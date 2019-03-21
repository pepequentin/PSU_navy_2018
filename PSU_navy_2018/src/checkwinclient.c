/*
** EPITECH PROJECT, 2019
** aie
** File description:
** aie
*/

#include "../include/my.h"

void check_win_client(int i, int j)
{
    if (game.enemy.themap[i][j] == '2')
        game.nbr_of_two++;
    if (game.enemy.themap[i][j] == '3')
        game.nbr_of_three++;
    if (game.enemy.themap[i][j] == '4')
        game.nbr_of_four++;
    if (game.enemy.themap[i][j] == '5')
        game.nbr_of_five++;
}

int otherother(void)
{
    kill(game.our.pid, SIGUSR1);
    usleep(5000);
    kill(game.our.pid, SIGUSR2);
    for (game.var_glob = 0; game.var_glob == 0;)
        game.trash = 0;
    if (game.var_glob == 2) {
        my_printf("\nI won\n");
        game.jo = 2;
    }
    return (-1);
}

void night(void)
{
    for (int i = 0; i != 2; i++) {
        kill(game.our.pid, SIGUSR1);
        usleep(5000);
    }
    kill(game.our.pid, SIGUSR2);
    usleep(5000);
}

int checkwin_client(void)
{
    game.nbr_of_two = 0;
    game.nbr_of_three = 0;
    game.nbr_of_four = 0;
    game.nbr_of_five = 0;

    for (int i = 0; i != 8; i++)
        for (int j = 0; j != 8; j++)
            check_win_client(i, j);
    if (game.nbr_of_two == 0 && game.nbr_of_three == 0 && \
        game.nbr_of_four == 0 && game.nbr_of_five == 0) {
        my_printf("\nEnemy won\n");
        night();
        return (0);
    }
    else {
        if (otherother() == 0)
            return (0);
        else
            return (-1);
    }
}