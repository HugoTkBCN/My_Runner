/*
** EPITECH PROJECT, 2018
** runner
** File description:
** fichier du runner
*/

#include "../include/my.h"

void do_move(all_game_t *all_game)
{
    int r_event = 0;
    int pos_y = 0;

    r_event = analyse_events(*all_game);
    pos_y = all_game->runner.position.y;
    if (r_event == 0 && all_game->runner_up <= 0 && pos_y == HEIGHT_FLOOR) {
        runner_run(all_game);
        all_game->runner_up = -1;
    } else if (r_event == SPACE_PRESSED) {
        all_game->runner_up = 1;
        runner_run(all_game);
    }
    make_the_jump(all_game);
}

void runner_run(all_game_t *all_game)
{
    sfRenderWindow_clear(all_game->window, sfBlack);
    all_game->runner.ptr_move(&all_game->runner);
    display_wallpaper(all_game->window, all_game->wall_paper);
    display_runner(all_game->window, all_game->runner);
}

void make_the_jump(all_game_t *all_game)
{
    sfVector2f move = {0, -30};
    sfVector2f move_down = {0, 15};

    if (all_game->runner_up >= 1 && all_game->runner.position.y > 0) {
        all_game->runner_up++;
        sfSprite_move(all_game->runner.sprite, move);
        runner_run(all_game);
        if (all_game->runner_up == 5)
            all_game->runner_up = 0;
    } else if (all_game->runner_up == 0 || all_game->runner.position.y <= 0) {
        all_game->runner_up = 0;
        sfSprite_move(all_game->runner.sprite, move_down);
        runner_run(all_game);
    }
}

void move_runner(game_object_t *runner)
{
    runner->rect.top = 0;
    runner->rect.left += WIDTH_RUNNER;
    runner->rect.width = WIDTH_RUNNER;
    if (runner->rect.left >= WIDTH_RUNNER_MAX)
        runner->rect.left = 0;
    runner->rect.height = HEIGHT_RUNNER;
}

void display_runner(sfRenderWindow *window, game_object_t runner)
{
    sfSprite_setTextureRect(runner.sprite, runner.rect);
    sfRenderWindow_drawSprite(window, runner.sprite, NULL);
}
