/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** display.c
*/

#include "../include/my.h"

static void display_towers(main_struct_t main)
{
    for (int i = 0; i < main.len_towers; i++){
        if (main.display_sprt)
            sfRenderWindow_drawSprite(main.wind.wind, main.all_towers[i].
            tower_sprt, NULL);
        sfRenderWindow_drawCircleShape(main.wind.wind, main.all_towers[i].
        circle, NULL);
    }
}

static void display_planes(main_struct_t *main)
{
    int time = sfClock_getElapsedTime(main->wind.my_clock).microseconds;
    int sec = time / 1000000;

    for (int i = 0; i < main->len_planes; i++){
        if ((main->all_planes[i].is_avail == sfFalse) &&
            (sec >= main->all_planes[i].delay))
            main->all_planes[i].is_avail = sfTrue;
        if (main->all_planes[i].is_avail == sfTrue)
            sfRenderWindow_drawRectangleShape(main->wind.wind, main->all_planes
            [i].rec, NULL);
    }
}

static void update_time(int *sec, int *min, main_struct_t main)
{
    int time = sfClock_getElapsedTime(main.wind.my_clock).microseconds;

    (*sec) = time / 1000000;
    while ((*sec) > 59){
        (*min)++;
        (*sec) -= 60;
    }
}

static void display_text(main_struct_t main)
{
    int sec = 0;
    int min = 0;
    char *time_sec = NULL;
    char *time_min = NULL;

    update_time(&sec, &min, main);
    time_sec = conversion_int_char(sec);
    time_min = conversion_int_char(min);
    if (time_sec != NULL && time_min != NULL){
        sfText_setString(main.wind.text, my_strcat(my_strcat(time_min, ":"),
        time_sec));
        sfRenderWindow_drawText(main.wind.wind, main.wind.text, NULL);
        free(time_sec);
        free(time_min);
        return;
    }
    if (time_min != NULL)
        free(time_min);
    if (time_sec != NULL)
        free(time_sec);
}

static void display_qt(main_struct_t main)
{
    for (int i = 0; i < main.len_qt; i++)
        if (main.display_qt == 1)
            sfRenderWindow_drawRectangleShape(main.wind.wind, main.my_qt
            [i].rec, NULL);
}

void display_assets(main_struct_t *main)
{
    sfRenderWindow_clear((*main).wind.wind, sfBlack);
    sfRenderWindow_drawSprite((*main).wind.wind, (*main).wind.bg_sprt, NULL);
    display_planes(main);
    display_towers(*main);
    display_text(*main);
    display_qt(*main);
    sfRenderWindow_display((*main).wind.wind);
}
