/*
** EPITECH PROJECT, 2018
** create game object
** File description:
** my_runner
*/

#include "../../include/my.h"

int get_len_map(char **map)
{
    int i;

    for (i = 0; map[i]; i++) {
    }
    return (i + 1);
}

all_game_t create_main_struct_2(all_game_t all_game, char **map)
{
    sfVector2f vector_obstacle = {0, 0};

    all_game.obstacle = create_array_obstacle(vector_obstacle);
    all_game.pos_cube1 = get_coord(map, '1');
    all_game.pos_cube2 = get_coord(map, '2');
    all_game.pos_pic = get_coord(map, '3');
    all_game.len_map = get_len_map(map);
    create_score(&all_game);
    create_pause(&all_game.pause, PATH_TO_PAUSE_MENU);
    create_pause(&all_game.lose, PATH_TO_LOSE);
    create_pause(&all_game.win, PATH_TO_WIN);
    create_menu(&all_game.menu);
    return (all_game);
}

all_game_t create_main_struct(all_game_t all_game, char **map)
{
    sfIntRect rect_wp = {0, 0, WIDTH_WP, HEIGHT_WP};
    sfIntRect rect_runner = {0, 0, WIDTH_RUNNER, HEIGHT_RUNNER};
    sfVector2f vctr_r = {(WIDTH_WP / 2) - (WIDTH_RUNNER / 2), HEIGHT_FLOOR};

    all_game.wall_paper = create_array_wallpaper(rect_wp, (sfVector2f){0 , 0});
    all_game.runner = create_runner(rect_runner, vctr_r);
    all_game.runner_up = 0;
    all_game.score = 0;
    all_game.b_put = 0;
    all_game.nbr_game = 0;
    all_game = create_main_struct_2(all_game, map);
    create_death_win_sound(&all_game);
    return (all_game);
}
