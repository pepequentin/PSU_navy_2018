/*
** EPITECH PROJECT, 2019
** aie
** File description:
** aie
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    my_allocmap();
    long i = getpid();
    if (ac == 2) {
        if (goodfile(av, 1) == -1 || parse_map(av[1]) == -1)
            return (put_error());
        game.our.pid = i;
        server(av);
    }
    else if (ac == 3) {
        if (goodfile(av, 2) == -1 || parse_map2(av[2]) == -1)
            return (put_error());
        game.enemy.pid = i;
        game.our.pid = my_get_nbr(av[1]);
        client(i, av);
    }
    else
        return (0);
    return (0);
}