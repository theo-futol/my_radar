/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** free_all.c
*/

#include "../include/my.h"

static void free_main(main_struct_t *data)
{
    sfTexture_destroy(data->wind.bg_txt);
    sfTexture_destroy(data->wind.tower_txt);
    sfTexture_destroy(data->wind.plane_txt);
    sfSprite_destroy(data->wind.bg_sprt);
    sfMusic_destroy(data->wind.sound);
    sfClock_destroy(data->wind.my_clock);
    sfFont_destroy(data->wind.font);
    sfText_destroy(data->wind.text);
}

void close_window(main_struct_t *data)
{
    free_main(data);
    for (int i = 0; i < data->len_towers; i++){
        if (data->all_towers[i].circle != NULL)
            sfCircleShape_destroy(data->all_towers[i].circle);
        if (data->all_towers[i].tower_sprt != NULL)
            sfSprite_destroy(data->all_towers[i].tower_sprt);
    }
    for (int i = 0; i < data->len_planes; i++)
        if (data->all_planes[i].rec != NULL)
            sfRectangleShape_destroy(data->all_planes[i].rec);
    for (int i = 0; i < data->len_qt; i++){
        if (data->my_qt[i].rec != NULL)
            sfRectangleShape_destroy(data->my_qt[i].rec);
        free(data->my_qt[i].id);
    }
    free(data->my_qt);
    free(data->all_planes);
    free(data->all_towers);
    sfRenderWindow_destroy(data->wind.wind);
}
