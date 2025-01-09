/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** move_planes.c
*/

#include "../include/my.h"

static void calcul_newpos(planes_t *plane)
{
    plane->pos.x += cos(plane->angle) * plane->speed / 60;
    plane->pos.y += sin(plane->angle) * plane->speed / 60;
    sfRectangleShape_setPosition(plane->rec, plane->pos);
}

static void is_arrival(planes_t *plane, main_struct_t *main)
{
    sfVector2f pos = plane->pos;
    sfVector2f arrival = plane->arrival;

    if (plane->arrival.x < plane->departure.x){
        pos.x = 1 / pos.x;
        arrival.x = 1 / arrival.x;
    }
    if (plane->arrival.y < plane->departure.y){
        pos.y = 1 / pos.y;
        arrival.y = 1 / arrival.y;
    }
    if ((pos.x >= arrival.x) && (pos.y >= arrival.y)){
        plane->is_avail = 2;
        is_finish(main, 1);
    }
}

void move_planes(main_struct_t *main)
{
    for (int i = 0; i < main->len_planes; i++){
        if (main->all_planes[i].is_avail == sfTrue){
            calcul_newpos(&main->all_planes[i]);
            is_arrival(&main->all_planes[i], main);
        }
    }
}
