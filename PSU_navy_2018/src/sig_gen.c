/*
** EPITECH PROJECT, 2019
** sig_gen.c
** File description:
** sig_gen
*/

#include "../include/my.h"

void handle_sig(int signum, siginfo_t *sig_inf, void *tmp)
{
    static int usr1 = 0;
    game.pid_ennemy = sig_inf->si_pid;
    game.enemy.pid = sig_inf->si_pid;

    if (signum == SIGUSR1)
        usr1++;
    else if (signum == SIGUSR2) {
        game.var_glob = usr1;
        usr1 = 0;
    }
}

void reception(char *line)
{
    int *res = malloc(20);

    res[0] = line[0] -'A' + 1;
    res[1] = line[1] - '0';
    for (int i = 0; i != res[0]; i++) {
        kill(game.pid_ennemy, SIGUSR1);
        usleep(5000);
    }
    kill(game.pid_ennemy, SIGUSR2);
    usleep(5000);
    for (int j = 0; j != res[1]; j++) {
        kill(game.pid_ennemy, SIGUSR1);
        usleep(5000);
    }
    kill(game.pid_ennemy, SIGUSR2);
}

char *put_caract(char *line)
{
    my_printf("\nattack: ");
    line = get_next_line(0);
    if (line[0] <= 'H' && line[0] >= 'A' && line[1] <= '8' &&
        line[1] >= '1' && my_strlen(line) == 2) {
        my_printf("%s: ", line);
        reception(line);
        return (line);
    }
    else {
        my_printf("wrong position");
        return (line);
    }
}