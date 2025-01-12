/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** quatree.c
*/

#include "../include/my.h"

static float get_dist_t(planes_t p1, towers_t t)
{
    return sqrt(pow((p1.pos.y + t.radius) - (t.pos.y + t.radius), 2) +
    pow((p1.pos.x + t.radius) - (t.pos.x + t.radius), 2));
}

static float get_dist_p(planes_t p1, planes_t p2)
{
    return sqrt(pow((p1.pos.y + 10) - (p2.pos.y + 10), 2) +
    pow((p1.pos.x + 10) - (p2.pos.x + 10), 2));
}

static int is_in_tower(planes_t p1, planes_t p2, main_struct_t main)
{
    for (int i = 0; i < main.len_towers; i++)
        if (get_dist_t(p1, main.all_towers[i]) < main.all_towers[i].radius ||
            get_dist_t(p2, main.all_towers[i]) < main.all_towers[i].radius)
            return 1;
    return 0;
}

static int is_hit(planes_t *p1, planes_t *p2, main_struct_t *main)
{
    if (get_dist_p(*p1, *p2) < 25 && (p1->is_avail ==
        sfTrue && p2->is_avail == sfTrue)){
        if (is_in_tower(*p1, *p2, *main) == 1)
            return 0;
        p1->is_avail = 2;
        p2->is_avail = 2;
        is_finish(main, 2);
    }
    return 0;
}

void check_collisions(main_struct_t *main, quadtree_t qt)
{
    for (int i = 0; i < qt.len_plane; i++)
        for (int j = i + 1; j < qt.len_plane; j++)
            is_hit(&main->all_planes[qt.id[i]], &main->all_planes[qt.id[j]],
            main);
}
