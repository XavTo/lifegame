/*
** EPITECH PROJECT, 2020
** gamefile
** File description:
** main
*/

#include "game.h"

static size_t split_find_nb_cell(game_t *game, int x, int y, size_t nb_cell)
{
    if (game->map[x + 1] != NULL) {
        if (game->map[x + 1][y] == BLACK)
            nb_cell++;
        if (y - 1 >= 0 && game->map[x + 1][y - 1] == BLACK)
            nb_cell++;
        if (game->map[x + 1][y + 1] != '\0' && game->map[x + 1][y + 1] == BLACK)
            nb_cell++;
    }
    if (y - 1 >= 0 && game->map[x][y - 1] == BLACK)
        nb_cell++;
    if (game->map[x][y + 1] != '\0' && game->map[x][y + 1] == BLACK)
        nb_cell++;
    return (nb_cell);
}

static size_t find_nb_cell(game_t *game, int x, int y, size_t nb_cell)
{
    if (x - 1 >= 0) {
        if (game->map[x - 1][y] == BLACK)
            nb_cell++;
        if (y - 1 >= 0 && game->map[x - 1][y - 1] == BLACK)
            nb_cell++;
        if (game->map[x][y] != '\0' && game->map[x - 1][y + 1] == BLACK)
            nb_cell++;
    }
    nb_cell = split_find_nb_cell(game, x, y, nb_cell);
    return (nb_cell);
}

static void check_cell(char **save_map, game_t *game, int x, int y)
{
    size_t nb_cell = 0;

    if (game->map[x][y] == WHITE) {
        nb_cell = find_nb_cell(game, x, y, nb_cell);
        if (nb_cell == 3)
            save_map[x][y] = BLACK;
    }
    else {
        nb_cell = find_nb_cell(game, x, y, nb_cell);
        if (nb_cell != 2 && nb_cell != 3)
            save_map[x][y] = WHITE;
    }
}

static void copy_and_free(char **save_map, char **map)
{
    size_t x = 0;
    size_t y = 0;
    char stock = 0;

    while (save_map[x] != NULL) {
        while (save_map[x][y] != '\0') {
            stock = save_map[x][y];
            map[x][y] = stock;
            y++;
        }
        y = 0;
        x++;
    }
    x = 0;
    while (save_map[x] != NULL) {
        free(save_map[x]);
        x++;
    }
    free(save_map[x]);
    free(save_map);
}

void update_map(game_t *game)
{
    int x = 0;
    int y = 0;
    char **save_map = NULL;

    save_map = my_copy_double_tab(game->map, save_map);
    while (game->map[x] != NULL) {
        while (game->map[x][y] != '\0') {
            check_cell(save_map, game, x, y);
            y++;
        }
        y = 0;
        x++;
    }
    copy_and_free(save_map, game->map);
}