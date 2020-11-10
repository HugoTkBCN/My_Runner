/*
** EPITECH PROJECT, 2019
** score game
** File description:
** my runner
*/

#include "../include/my.h"

void create_score(all_game_t *all_game)
{
    all_game->score_text.text = sfText_create();
    all_game->score_game.text = sfText_create();
    all_game->score_text.pos = (sfVector2f){X_SCORE, Y_SCORE};
    all_game->score_game.pos = (sfVector2f){X_SCORE + 200, Y_SCORE};
    all_game->score_text.font = sfFont_createFromFile(PATH_TO_FONT);
    all_game->score_game.font = sfFont_createFromFile(PATH_TO_FONT);
    sfText_setString(all_game->score_text.text, "Score :");
    sfText_setColor(all_game->score_text.text, sfWhite);
    sfText_setPosition(all_game->score_text.text, all_game->score_text.pos);
    sfText_setCharacterSize(all_game->score_text.text, SIZE_TEXT);
    sfText_setFont(all_game->score_text.text, all_game->score_text.font);
}

void put_score(all_game_t all_game)
{
    sfText_setString(all_game.score_game.text, int_to_str(all_game.score));
    sfText_setColor(all_game.score_game.text, sfWhite);
    sfText_setPosition(all_game.score_game.text, all_game.score_game.pos);
    sfText_setCharacterSize(all_game.score_game.text, SIZE_TEXT);
    sfText_setFont(all_game.score_game.text, all_game.score_game.font);
    sfRenderWindow_drawText(all_game.window, all_game.score_text.text, 0);
    sfRenderWindow_drawText(all_game.window, all_game.score_game.text, 0);
}
