/*
** EPITECH PROJECT, 2020
** ai.h
** File description:
** fichier h prototypes
*/

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

#define WHITE '0'
#define BLACK '1'

typedef struct {
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    char **map;
    int speed;
    int cycle;
    bool start;
    bool pause;
    bool end;
    bool scroll;
    sfVector2f wd_size;
    sfVector2f map_size;
} game_t;

void game_loop(game_t *game);
void update_map(game_t *game);
void event_pause(game_t *game);
void display_info(game_t *game);
void display_pause(game_t *game);
void clean_map(game_t *game);
void my_scroll_zom(game_t *game);
void my_scroll_dez(game_t *game);
void display_map(game_t *game);

#endif