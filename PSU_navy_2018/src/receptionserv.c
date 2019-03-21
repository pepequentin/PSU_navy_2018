/*
** EPITECH PROJECT, 2019
** aie
** File description:
** aie
*/

#include "../include/my.h"

void reception_our(char *line)
{
    int *res = malloc(20);
    res[0] = line[0] -'A' + 1;
    res[1] = line[1] - '0';
    for (int i = 0; i != res[0]; i++) {
        kill(game.our.pid, SIGUSR1);
        usleep(5000);
    }
    kill(game.our.pid, SIGUSR2);
    usleep(5000);
    for (int j = 0; j != res[1]; j++) {
        kill(game.our.pid, SIGUSR1);
        usleep(5000);
    }
    kill(game.our.pid, SIGUSR2);
    usleep(5000);
}

char *put_caract_our(char *line)
{
    my_printf("\nattack: ");
    line = get_next_line(0);
    if (line[0] <= 'H' && line[0] >= 'A' && line[1] <= '8' &&
        line[1] >= '1' && my_strlen(line) == 2) {
        my_printf("%s: ", line);
        reception_our(line);
        return (line);
    }
    else {
        my_printf("wrong position");
        return (line);
    }
}