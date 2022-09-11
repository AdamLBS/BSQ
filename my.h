/*
** EPITECH PROJECT, 2021
** bsq2
** File description:
** my
*/
#include "structure.h"
#ifndef MY_H_
    #define MY_H_
    char *array_to_str(char **map, int size);
    int get_nbr_line(int number);
    int fs_open_file (char const *filepath);
    char *get_file(char const  *filepath);
    char **mem_alloc_2d_array (int nb_rows, int nb_cols);
    char **str_to_array(char *str, int nb_rows, int nb_cols);
    int get_cols(char *file, int line_jump);
    int is_square_of_size(char **map, int row, int col, int square_size);
    char *array_to_str(char **map, int size);
    int get_char_val(char **map);
    int get_biggest_square(struct val values, char **map_2);
    int draw_square(struct res result);
    int count_numbers(char *file);
    int compare_lines(char *filepath);
    int my_get_nbr(const char *str);
    void my_putchar (char c);
    int print_defmap(char **map, int res_val);
    int my_putstr(char const *str);
    int compute_sq(struct res result, int square);
#endif /* !MY_H_ */
