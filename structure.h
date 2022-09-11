/*
** EPITECH PROJECT, 2021
** bsq2
** File description:
** structure
*/

#ifndef STRUCTURE_H_
    #define STRUCTURE_H_
    struct val {
        char **map;
        int rows;
        int cols;
        int square;
        int full_row;
        int full_col;
        int full_size;
        int biggest_square;
    } typedef values;

    struct res {
        char **map_2;
        int cols_big;
        int raw_big;
        int square;
        int full_size;
    } typedef result;

#endif /* !STRUCTURE_H_ */
