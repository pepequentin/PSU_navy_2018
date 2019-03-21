/*
** EPITECH PROJECT, 2018
** struct
** File description:
** struct
*/

#pragma once
#include <stdarg.h>
#include "struct.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>

# define game me_t

typedef struct player_s {
    char **themap;
    char **voidmap;
    pid_t pid;
} player_t;

struct me_s {
    player_t enemy;
    player_t our;
    char *letters;
    char *tir;
    int a_to;
    int a_from;
    int b_to;
    int b_from;
    int var_glob;
    int nbr_of_two;
    int nbr_of_three;
    int nbr_of_four;
    int nbr_of_five;
    int pid_ennemy;
    int pid_our;
    char pos_l;
    char pos_nbr;
    int temp;
    int i;
    int jo;
    int trash;
} me_t;

void print_map_our(void);
int goodfile(char **av, int who);
char *get_next_line(int fd);
int parse_map(char *filepath);
int parse_map2(char *filepath);
void print_map_enemy();
void print_map_client();
int my_get_nbr(char *str);
void my_allocmap();
int my_printf(char *str, ...);
int nodiago_one();
void error_diag_one(int i, int j);
int nodiago_two();
void error_diag_two(int i, int j);
int put_error();
char *put_caract(char *line);

void handle_sig(int signum, siginfo_t *sig_inf, void *tmp);
void who_sig_me(char **av);
void server(char **av);
void client(long i, char **av);
int my_strlen(char *str);

void suiteone(int i, int j);
void suitetwo(int hey);
void suitethree(int hey);
void suitefour(int, int);
void suitefive(int);
void suitesix(int);

void print_map_vide_client(void);
void print_map_vide_our(void);

void defence_client(void);
void defence_serv(void);
void attack_client(void);
void attack_serv(void);

char *put_caract_our(char *line);
int checkwin_serv(void);
int checkwin_client(void);

void suitenine(int hey);
void suiteten(int hey);
void followtwo(int hey);
void followthree(int hey);
void followfour(int hey);