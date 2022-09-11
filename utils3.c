/*
** EPITECH PROJECT, 2021
** bsq2
** File description:
** utils3
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "my.h"

int compute_sq(struct res result, int square)
{
    if (square == 0)
        return 84;
    else
        draw_square(result);
    return square;
}

int print_defmap(char **map, int res_val)
{
    if (res_val == 84) {
        for (int i = 0; map[i] != NULL; i++)
            my_putstr(map[i]);
    }
    return 0;
}

int count_numbers(char *file)
{
    int i = 0;
    while (file[i] >= '0' && file[i] <= '9' || file[i] == '\n'){
        i++;
    }
    return i;
}

int compare_lines(char *filepath)
{
    char *src = get_file(filepath);
    int line = 0;
    int i = count_numbers(src);
    for (; src[i] != '\0'; i++){
        if (src[i] == '\n'){
            line++;
        }
    }
    int new_line = 0;
    new_line = my_get_nbr(src);
    if (new_line != line){
        return 84;
    }
    else
        return 0;
}

int get_cols(char *file, int line_jump)
{
    int i = 0;
    while (file[line_jump] != '\n') {
        line_jump++;
        i++;
    }
    return i;
}