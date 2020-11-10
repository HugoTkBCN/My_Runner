/*
** EPITECH PROJECT, 2019
** generate blocks
** File description:
** runner
*/

#include "../include/my.h"

int get_nb_bls(char **map, char type)
{
    int c = 0;

    for (int i = 0; map[i]; i++) {
        for (int y = 0; map[i][y]; y++) {
            c = map[i][y] == type ? c + 1 : c;
        }
    }
    return (c);
}

sfVector2f *get_coord(char **map, char type)
{
    sfVector2f *coord = malloc(sizeof(sfVector2f) * get_nb_bls(map, type) + 1);
    int c = 0;

    for (int x = 0; map[x]; x++) {
        for (int y = 0; map[x][y]; y++) {
            coord[c].x = map[x][y] == type ? (x + 1) * 105 + WIDTH_WP : 0;
            coord[c].y = map[x][y] == type ? y * WIDTH_BLOCK + 25 : 0;
            c = map[x][y] == type ? c + 1 : c;
        }
    }
    coord[c].x = 0;
    coord[c].y = 0;
    return (coord);
}
