/*
** EPITECH PROJECT, 2021
** bsq2
** File description:
** utils2
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

char *array_to_str(char **map, int size)
{
    int i = 0;
    int j = 0;
    int full = 0;
    char *final_map = malloc(sizeof(char) * (size + 1));
    while (map[i] != NULL){
        while (map[i][j] != '\0'){
            final_map[full] = map[i][j];
            j++;
            full++;
        }
        j = 0;
        i++;
    }
    return final_map;
}

int get_char_val(char **map)
{
    int i = 0;
    while (map[0][i] != '\n')
        i++;
    i++;
    return i;
}