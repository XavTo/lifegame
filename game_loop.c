/*
** EPITECH PROJECT, 2020
** gamefile
** File description:
** main
*/

#include "game.h"

static void display_rect(game_t *game, char val, sfVector2f pos)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size = {
        game->wd_size.x / game->map_size.x, game->wd_size.y / game->map_size.y};

    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setOutlineThickness(rect, 1);
    if (val == WHITE) {
        sfRectangleShape_setOutlineColor(rect, sfBlack);
        sfRectangleShape_setFillColor(rect, sfWhite);
    }
    else {
        sfRectangleShape_setOutlineColor(rect, sfWhite);
        sfRectangleShape_setFillColor(rect, sfBlack);
    }
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

void display_map(game_t *game)
{
    size_t x = 0;
    size_t y = 0;
    sfVector2f pos = {0, 0};

    while (game->map[x] != NULL) {
        while (game->map[x][y] != '\0') {
            display_rect(game, game->map[x][y], pos);
            y++;
            pos.y += game->wd_size.y / game->map_size.y;
        }
        y = 0;
        pos.y = 0;
        pos.x += game->wd_size.x / game->map_size.x;
        x++;
    }
}

static void create_cell(game_t *game)
{
    float x = 0;
    float y = 0;
    int stockx = 0;
    int stocky = 0;
    int divx = game->wd_size.x / game->map_size.x;
    int divy = game->wd_size.y / game->map_size.y;

    if (game->event.type == sfEvtMouseButtonPressed) {
        x = sfMouse_getPositionRenderWindow(game->window).x;
        y = sfMouse_getPositionRenderWindow(game->window).y;
        stockx = x / divx;
        stocky = y / divy;
        game->map[stockx][stocky] = BLACK;
    }
}

static void my_event(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed || game->end == true)
            sfRenderWindow_close(game->window);
        event_pause(game);
        if (sfKeyboard_isKeyPressed(sfKeyUp) && game->map_size.x > 30)
            my_scroll_zom(game);
        if (sfKeyboard_isKeyPressed(sfKeyDown) && game->map_size.x < 240)
            my_scroll_dez(game);
        if (sfKeyboard_isKeyPressed(sfKeyLeft)
            && game->start == false && game->speed >= 50000)
            game->speed -= 50000;
        if (sfKeyboard_isKeyPressed(sfKeyRight) && game->speed <= 7500000)
            game->speed += 50000;
        if (game->start == true)
            create_cell(game);
        if (sfKeyboard_isKeyPressed(sfKeyReturn) && game->start == true) {
            game->start = false;
            sfClock_restart(game->clock);
        }
    }
}

void game_loop(game_t *game)
{
    game->clock = sfClock_create();

    while (sfRenderWindow_isOpen(game->window)) {
        my_event(game);
        sfRenderWindow_clear(game->window, sfBlack);
        if (game->pause == false && sfClock_getElapsedTime(game->clock)
            .microseconds >= game->speed && game->start == false) {
            sfClock_restart(game->clock);
            update_map(game);
            game->cycle++;
        }
        display_map(game);
        if (game->start == false)
            display_info(game);
        if (game->pause == true)
            display_pause(game);
        sfRenderWindow_display(game->window);
    }
}