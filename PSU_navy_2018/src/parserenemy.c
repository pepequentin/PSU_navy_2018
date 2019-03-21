/*
** EPITECH PROJECT, 2019
** aie
** File description:
** aie
*/

#include "../include/my.h"

static void two(int hey)
{
    if (game.a_from == game.b_from)
        suitefive(hey);
    else
        suitesix(hey);
}

void error_diag_two(int i, int j)
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

int nodiago_two(void)
{
    game.nbr_of_two = 0;
    game.nbr_of_three = 0;
    for (int i = 0; i != 8; i++)
        for (int j = 0; j != 8; j++)
            error_diag_two(i, j);
    if (game.nbr_of_two == 2 && game.nbr_of_three == 3 && \
        game.nbr_of_four == 4 && game.nbr_of_five == 5)
        return (0);
    else
        return (-1);
}

void pointtwo(void)
{
    for (int i = 0; i != 8; i++) {
        for (int j = 0; j != 8; j++) {
            suitefour(i, j);
        }
    }
}

int parse_map2(char *filepath)
{
    int fd;
    int hey;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return -1;
    for (char *line; (line = get_next_line(fd)) != NULL;) {
        game.a_from = line[2] - 'A';
        game.a_to = line[3] - '1';
        game.b_from = line[5] - 'A';
        game.b_to = line[6] - '1';
        two(hey);
        hey += 1;
    }
    pointtwo();
    close(fd);
    if (nodiago_two() == -1)
        return (-1);
    return (0);
}