/*
** EPITECH PROJECT, 2019
** client.c
** File description:
** client.c
*/

#include "../include/my.h"

void handle_sig_client(int signum, siginfo_t *sig_inf, void *tmp)
{
    static int usr1 = 0;
    game.pid_ennemy = sig_inf->si_pid;
    game.our.pid = sig_inf->si_pid;

    if (signum == SIGUSR1)
        usr1++;
    else if (signum == SIGUSR2) {
        game.var_glob = usr1;
        usr1 = 0;
    }
}

void who_sig_me_client(char **av)
{
    struct sigaction sig;

    sig.sa_sigaction = handle_sig_client;
    sigemptyset(&(sig.sa_mask));
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    for (game.jo = 1; game.jo == 1;) {
        my_printf("my positions:\n");
        print_map_enemy();
        print_map_vide_client();
        usleep(5000);
        my_printf("\nwaiting for enemy's attack...\n");
        defence_client();
        attack_client();
        if (checkwin_client() == 0)
            game.jo = 2;
    }
}

void client(long i, char **av)
{
    if ((i = kill(game.our.pid, SIGUSR1) == 0)) {
        my_printf("my_pid: %d\n", game.enemy.pid);
        my_printf("successfully connected\n\n");
        who_sig_me_client(av);
    }
    else
        my_printf("wrong pid\n");
}