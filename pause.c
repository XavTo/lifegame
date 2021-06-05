/*
** EPITECH PROJECT, 2020
** gamelife
** File description:
** pause
*/

#include "game.h"

static void display_text_quit(game_t *game, int bold)
{
    sfFont* font = sfFont_createFromFile("font.ttf");
    sfText* text = sfText_create();
    sfVector2f pos = {10, 400};

    sfText_setString(text, "Quit");
    if (bold == 3)
        sfText_setColor(text, sfGreen);
    else
        sfText_setColor(text, sfBlue);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void display_text_resume(game_t *game, int bold)
{
    sfFont* font = sfFont_createFromFile("font.ttf");
    sfText* text = sfText_create();
    sfVector2f pos = {10, 300};

    sfText_setString(text, "Resume");
    if (bold == 2)
        sfText_setColor(text, sfGreen);
    else
        sfText_setColor(text, sfBlue);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
    display_text_quit(game, bold);
}

static void display_text_restart(game_t *game, int bold)
{
    sfFont* font = sfFont_createFromFile("font.ttf");
    sfText* text = sfText_create();
    sfVector2f pos = {10, 200};

    sfText_setString(text, "Restart");
    if (bold == 1)
        sfText_setColor(text, sfGreen);
    else
        sfText_setColor(text, sfBlue);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
    display_text_resume(game, bold);
}

void display_pause(game_t *game)
{
    int x = sfMouse_getPositionRenderWindow(game->window).x;
    int y = sfMouse_getPositionRenderWindow(game->window).y;
    int bold = 0;

    if (x >= 10 && x <= 230 && y >= 200 && y <= 250)
        bold = 1;
    if (x >= 10 && x <= 245 && y >= 300 && y <= 350)
        bold = 2;
    if (x >= 10 && x <= 130 && y >= 400 && y <= 450)
        bold = 3;
    display_text_restart(game, bold);
    if (game->event.type == sfEvtMouseButtonPressed) {
        if (bold == 1)
            clean_map(game);
        if (bold == 2)
            game->pause = false;
        if (bold == 3)
            game->end = true;
    }
}

void event_pause(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        game->pause = true;
    if (sfKeyboard_isKeyPressed(sfKeyP))
        game->pause = false;
}