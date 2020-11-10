/*
** EPITECH PROJECT, 2018
** mem alloc 2d array
** File description:
** bootstrap bsq
*/

#include "../include/my.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **array = malloc(sizeof(char *) * nb_rows + 1);

    for (int i = 0; i != nb_rows; i++) {
        array[i] = malloc(sizeof(char) * nb_cols + 1);
    }
    return (array);
}
