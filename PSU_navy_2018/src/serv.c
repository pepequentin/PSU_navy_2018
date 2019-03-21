/*
** EPITECH PROJECT, 2019
** serv.c
** File description:
** serv.c
*/

#include "../include/my.h"

void who_sig_me(char **av)
{
    struct sigaction sig;
    sig.sa_sigaction = handle_sig;
    sigemptyset(&(sig.sa_mask));
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    pause();
    my_printf("\nenemy connected");
    for (game.jo = 1; game.jo == 1;) {
        my_printf("\nmy positions:\n");
        print_map_our();
        print_map_vide_our();
        if (game.temp == 0)
            game.i = game.pid_ennemy;
        attack_serv();
        defence_serv();
        game.pid_ennemy = game.i;
        game.temp++;
        if (checkwin_serv() == 0)
            game.jo = 2;
    }
}

void server(char **av)
{
    game.temp = 0;
    my_printf("my_pid: %d\nwaiting for enemy connection...\n", game.our.pid);
    who_sig_me(av);
}