/*
** EPITECH PROJECT, 2019
** aie
** File description:
** aie
*/

#include "../include/my.h"

void check_win(int i, int j)
{
    if (game.our.themap[i][j] == '2')
        game.nbr_of_two++;
    if (game.our.themap[i][j] == '3')
        game.nbr_of_three++;
    if (game.our.themap[i][j] == '4')
        game.nbr_of_four++;
    if (game.our.themap[i][j] == '5')
        game.nbr_of_five++;
}

int other(void)
{
    if (game.nbr_of_two == 0 && game.nbr_of_three == 0 && \
        game.nbr_of_four == 0 && game.nbr_of_five == 0) {
        my_printf("\nEnemy won\n");
        for (int i = 0; i != 2; i++) {
            kill(game.i, SIGUSR1);
            usleep(5000);
        }
        kill(game.i, SIGUSR2);
        usleep(400);
        return (0);
    }
    else {
        kill(game.i, SIGUSR1);
        usleep(400);
        kill(game.i, SIGUSR2);
        return (-1);
    }
}

int checkwin_serv(void)
{
    game.nbr_of_two = 0;
    game.nbr_of_three = 0;
    game.nbr_of_four = 0;
    game.nbr_of_five = 0;

    for (game.var_glob = 0; game.var_glob == 0;)
        game.trash = 0;
    if (game.var_glob == 2) {
        my_printf("\nI won\n");
        game.jo = 2;
        return (-1);
    }
    for (int i = 0; i != 8; i++)
        for (int j = 0; j != 8; j++)
            check_win(i, j);
    if (other() == 0)
        return (0);
    else
        return (-1);
}