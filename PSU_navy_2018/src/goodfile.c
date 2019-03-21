/*
** EPITECH PROJECT, 2019
** aie
** File description:
** aie
*/

#include "../include/my.h"

int goodfile(char **av, int who)
{
    int fd;
    if ((fd = open(av[who], O_RDONLY)) < 0)
        return (-1);
    int temp = 0;
    int i = 0;
    for (char *str; (str = get_next_line(fd)) != NULL;) {
        for (int i = 0; str[i] != '\0'; i++)
            if (i > 6)
                return (-1);
        if (str[0] > 54 || str[0] < 49 || str[1] != 58 || str[4] != 58)
            return (-1);
        if (str[2] < 65 || str[2] > 72 || str[5] < 65 || str[5] > 72)
            return (-1);
        temp++;
    }
    if (temp != 4)
        return (-1);
    return (0);
}