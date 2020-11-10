/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** main fonction
*/

#include "include/my.h"

void put_all_sprite(all_game_t all_game)
{
    sfRenderWindow_clear(all_game.window, sfBlack);
    display_wallpaper(all_game.window, all_game.wall_paper);
    display_runner(all_game.window, all_game.runner);
    put_blocks(&all_game, 1);
    put_score(all_game);
}

void init_game(all_game_t *all_game)
{
    all_game->pos_cube1 = get_coord(all_game->map, '1');
    all_game->pos_cube2 = get_coord(all_game->map, '2');
    all_game->pos_pic = get_coord(all_game->map, '3');
    all_game->score = 0;
    all_game->b_put = 0;
    all_game->nbr_game = 0;
}

int my_runner(all_game_t all_game)
{
    all_game.window = open_window(WIDTH_WP, HEIGHT_WP, "my_flyer");
    sfRenderWindow_setFramerateLimit(all_game.window, 25);
    put_menu(all_game);
    while (sfRenderWindow_isOpen(all_game.window)) {
        all_game.runner.position = sfSprite_getPosition(all_game.runner.sprite);
        for (int i = 0; i < 3; i++)
            all_game.wall_paper[i].ptr_move(&all_game.wall_paper[i]);
        do_move(&all_game);
        put_blocks(&all_game, 0);
        put_score(all_game);
        sfRenderWindow_display(all_game.window);
        if ((collision(all_game)) == 1) {
            sfSound_play(all_game.death.sound);
            restart(&all_game, 0);
        } else if (all_game.nbr_game == 1) {
            sfSound_play(all_game.win_sound.sound);
            restart(&all_game, 1);
        }
    }
    return (0);
}
