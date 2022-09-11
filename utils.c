/*
** EPITECH PROJECT, 2021
** bsq2
** File description:
** utils
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

int get_nbr_line(int number)
{
    int count = 0;
    if (number < 0)
        count++;
    while (number != 0){
        count++;
        number = number / 10;
    }
    count++;
    return count;
}

int fs_open_file (char const *filepath)
{

    int fd = open(filepath, O_RDONLY);
    if (fd == -1){
        return (84);
    } else
        return 0;
}

char *get_file(char const  *filepath)
{
    struct stat info;
    stat(filepath, &info);
    int size = info.st_size;
    char *file = malloc(sizeof(char) * size + 1);
    int fd = open(filepath, O_RDONLY);
    read(fd, file, size);
    close (fd);
    return (file);
}

char **mem_alloc_2d_array (int nb_rows, int nb_cols)
{
    char **my_char = malloc(sizeof(char *) * nb_rows + 1);
    for (int i = 0; nb_rows >= 0; nb_rows--){
        my_char[i] = malloc(sizeof(char) * nb_cols + 1);
        i++;
    }
    return my_char;
}