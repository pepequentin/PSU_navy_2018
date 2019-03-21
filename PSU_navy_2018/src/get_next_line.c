/*
** EPITECH PROJECT, 2018
** me
** File description:
** me
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/get_next_line.h"

void init(my_get_t *lod)
{
    lod->len = 0;
    lod->constance = 0;
    lod->temp = 0;
    lod->str = malloc(6000 + 1);
    lod->str2 = malloc(6000 + 1);
}

char *get_next_line(int fd)
{
    my_get_t lod;
    static char buff[READ_SIZE];

    init(&lod);
    if (lod.str == NULL || lod.str2 == NULL)
        return (0);
    lod.str[0] = '\0';
    lod.len = 0;
    for (; (lod.constance = read(fd, buff, READ_SIZE)) > 0 && \
    buff[0] != '\n'; lod.len++) {
        lod.str2[lod.len] = lod.str[lod.len];
        lod.str2[lod.len + 1] = '\0';
        lod.str2[lod.len] = buff[0];
    }
    if (lod.constance == 0 && lod.str2[0] == 0)
        return (NULL);
    return (lod.str2);
}
