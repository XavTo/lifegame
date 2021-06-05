/*
** EPITECH PROJECT, 2020
** gamelife
** File description:
** pause
*/

#include "game.h"

void clean_map(game_t *game)
{
    size_t y = 0;
    size_t x = 0;

    while (game->map[x] != NULL) {
        while (game->map[x][y] != '\0') {
            game->map[x][y] = WHITE;
            y++;
        }
        y = 0;
        x++;
    }
    game->start = true;
    game->pause = false;
    game->cycle = 0;
    game->speed = 300000;
    sfClock_restart(game->clock);
}

void display_info(game_t *game)
{
    sfFont* font = sfFont_createFromFile("font.ttf");
    sfText* text = sfText_create();
    sfVector2f pos = {10, 10};
    char *str = my_itoa(game->cycle);

    if (str[0] == '0')
        sfText_setString(text, "0");
    else
        sfText_setString(text, str);
    sfText_setColor(text, sfRed);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 45);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
    free(str);
}