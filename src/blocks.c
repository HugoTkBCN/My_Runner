/*
** EPITECH PROJECT, 2019
** put blocks
** File description:
** my runner
*/

#include "../include/my.h"

void move_blk(sfVector2f* pos, int b_pt, sfSprite *sprite, all_game_t *all_game)
{
    for (int i = 0; pos[i].x; i++) {
        if (pos[i].x == (b_pt + 1) * SPEED_BLK + WIDTH_WP) {
            pos[i].x = WIDTH_WP;
        } else if (pos[i].x <= (b_pt + 1) * SPEED_BLK + WIDTH_WP) {
            pos[i].x -= pos[i].x != SPEED_BLK ? SPEED_BLK : SPEED_BLK + 1;
        }
    }
}

void draw_blk(sfVector2f* pos, int b_pt, sfSprite *sprite, all_game_t *all_game)
{
    for (int i = 0; pos[i].x; i++) {
        if (pos[i].x <= (b_pt + 1) * 15 + WIDTH_WP) {
            sfSprite_setPosition(sprite, pos[i]);
            sfRenderWindow_drawSprite(all_game->window, sprite, NULL);
        }
    }
}

int reload_map(all_game_t *all_game)
{
    all_game->b_put = 0;
    all_game->pos_cube1 = get_coord(all_game->map, '1');
    all_game->pos_cube2 = get_coord(all_game->map, '2');
    all_game->pos_pic = get_coord(all_game->map, '3');
    all_game->nbr_game++;
    return (all_game->b_put);
}

void put_blocks(all_game_t *all_game, int choice)
{
    int b_put = all_game->b_put;
    sfVector2f **ar_pos = malloc(sizeof(sfVector2f*) * 3);

    if (b_put == all_game->len_map * 2 + (LEN_MAP - 10) * (SPEED_BLK - 5))
        b_put = reload_map(all_game);
    ar_pos[0] = all_game->pos_cube1;
    ar_pos[1] = all_game->pos_cube2;
    ar_pos[2] = all_game->pos_pic;
    if (choice == 0) {
        for (int i = 0; i < 3; i++) {
            move_blk(ar_pos[i], b_put, all_game->obstacle[i].sprite, all_game);
            draw_blk(ar_pos[i], b_put, all_game->obstacle[i].sprite, all_game);
        }
        all_game->b_put++;
        all_game->score += 10;
    } else
        for (int i = 0; i < 3; i++)
            draw_blk(ar_pos[i], b_put, all_game->obstacle[i].sprite, all_game);
    free(ar_pos);
}
