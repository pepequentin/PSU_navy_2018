/*
** EPITECH PROJECT, 2019
** aie
** File description:
** aie
*/

#include "../include/my.h"

void print_client(char *temp)
{
    for (game.var_glob = 0; game.var_glob == 0;)
        game.trash = 0;
    if (game.var_glob == 1) {
        my_printf("hit\n");
        game.enemy.voidmap[temp[1] - '0' - 1][temp[0] - 'A'] = 'x';
    }
    if (game.var_glob != 1) {
        my_printf("missed\n");
        game.enemy.voidmap[temp[1] - '0' - 1][temp[0] - 'A'] = 'o';
    }
}

void print_serv(char *temp)
{
    for (game.var_glob = 0; game.var_glob == 0;)
        game.trash = 0;
    if (game.var_glob == 1 || (game.temp == 0 && game.var_glob == 2)) {
        my_printf("hit\n");
        game.our.voidmap[temp[1] - '0' - 1][temp[0] - 'A'] = 'x';
    }
    else {
        my_printf("missed\n");
        game.our.voidmap[temp[1] - '0' - 1][temp[0] - 'A'] = 'o';
    }
}

void attack_client(void)
{
    char *line;
    char *temp = malloc(10);

    while (line) {
        line = put_caract_our(line);
        if (line[0] <= 'H' && line[0] >= 'A' && line[1] <= '8' &&
            line[1] >= '1' && my_strlen(line) == 2) {
                temp[0] = line[0];
                temp[1] = line[1];
                line = NULL;
            }
    }
    print_client(temp);
}

void attack_serv(void)
{
    char *line;
    char *temp = malloc(10);
    while (line) {
        line = put_caract(line);
        if (line[0] <= 'H' && line[0] >= 'A' && line[1] <= '8' &&
            line[1] >= '1' && my_strlen(line) == 2) {
                temp[0] = line[0];
                temp[1] = line[1];
                line = NULL;
            }
    }
    print_serv(temp);
}