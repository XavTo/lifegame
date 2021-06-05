/*
** EPITECH PROJECT, 2020
** display double tab
** File description:
** copy fonction
*/

#include <stddef.h>

void my_putchar(char c);

void my_putstr(char *str);

void display_double_tab(char **tab)
{
    size_t i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
}