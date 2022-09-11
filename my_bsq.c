/*
** EPITECH PROJECT, 2021
** bsq2
** File description:
** my_bsq
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

char **str_to_array(char *str, int nb_rows, int nb_cols)
{
    int run = 0;
    int j = 0;
    int i = 0;
    char **tmp_map = mem_alloc_2d_array(nb_rows, nb_cols);

    while (str[run] != '.' && str[run] != 'o') {
        run++;
    }

    for (i = 0; i < nb_rows; i++) {
        for (j = 0; j < nb_cols; j++) {
            tmp_map[i][j] = str[run];
            run++;
        }
        tmp_map[i][j] = '\n';
        run++;
        j = 0;
    }
    tmp_map[i+1] = NULL;
    return tmp_map;
}

int is_square_of_size(char **map, int row, int col, int square_size)
{
    int i = 0;
    int row_tmp = row;
    int col_tmp = col;
    while (row_tmp < (row + square_size)) {
        while (col_tmp < (col + square_size)) {
            if (map[row_tmp][col_tmp] != '.')
                return (0);
            i++;
            col_tmp++;
        }
        row_tmp++;
        col_tmp = col;
    }
    if (i == square_size * square_size)
        return (1);
}

int draw_square(struct res result)
{
    int full_cols = result.cols_big;
    int square = result.square;
    int raw = result.raw_big;
    int run = 0;
    int full_run = 0;
    while (full_run != square){
        while (run != square){
            result.map_2[raw][result.cols_big] = 'x';
            run++;
            result.cols_big++;
    }
        raw++;
        run = 0;
        full_run++;
        result.cols_big = full_cols;
    }
    char *full_map = array_to_str(result.map_2, result.full_size);
    write(1, full_map, result.full_size);
}

int get_biggest_square(struct val values, char **map_2)
{
    struct res result;
    int square = 1, biggest_square = 0;
    result.full_size = values.full_size;
    for (; values.full_row >= values.rows; values.rows = values.rows + 1){
        for (;values.full_col >= values.cols; values.cols = values.cols + 1){
            for (;is_square_of_size(values.map, values.rows, values.cols,
            square) == 1; square++){
                if (square > biggest_square){
                    result.cols_big = values.cols;
                    result.raw_big = values.rows;
                    result.map_2 = map_2, result.square = square;
                }
            }
        }
        values.cols = 0;
    }
    square--;
    if (square > biggest_square)
        biggest_square = square;
    return (compute_sq(result, square));
}

int main (int ac, char **av)
{
    if (ac != 2)
        return (84);
    int open = fs_open_file(av[1]);
    int lines = compare_lines(av[1]);
    if (lines == 84 || open == 84)
        return 84;
    char *file = get_file(av[1]);
    int nb = my_get_nbr(file);
    int line_jump = get_nbr_line(nb);
    int cols = get_cols(file, line_jump);
    char **map = str_to_array(file, nb, cols);
    char **map_2 = str_to_array(file, nb, cols);
    int size = get_char_val(map_2) * nb;
    struct val values = {map, 0, 0, 0, nb, cols, size};
    int return_val = get_biggest_square(values, map_2);
    print_defmap(map, return_val);
    return 0;
}
