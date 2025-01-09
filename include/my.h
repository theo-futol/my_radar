/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

// All include
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <limits.h>
    #include <math.h>
// My structs
typedef struct my_window {
    sfVideoMode mode;
    sfRenderWindow *wind;
    sfSprite *bg_sprt;
    sfTexture *bg_txt;
    sfTexture *tower_txt;
    sfTexture *plane_txt;
    sfFont *font;
    sfText *text;
    sfMusic *sound;
    sfClock *my_clock;
} my_window_t;
typedef struct planes {
    sfVector2f departure;
    sfVector2f arrival;
    sfVector2f pos;
    float angle;
    int is_avail;
    sfRectangleShape *rec;
    int speed;
    int delay;
} planes_t;
typedef struct towers {
    sfSprite *tower_sprt;
    sfVector2f pos;
    int radius;
    sfCircleShape *circle;
} towers_t;
typedef struct quadtree {
    int *id;
    int len_plane;
    sfVector2f zone;
    sfVector2f size;
    sfRectangleShape *rec;
} quadtree_t;
typedef struct main_struct {
    my_window_t wind;
    planes_t *all_planes;
    int planes_avail;
    int len_planes;
    towers_t *all_towers;
    int len_towers;
    int display_qt;
    int display_sprt;
    quadtree_t *my_qt;
    int len_qt;
} main_struct_t;
// Prototype of function
int my_strlen(char const *str);
int my_putchar(char c);
int my_putstr(char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strlowcase(char *str);
int parsing_file(char *path, main_struct_t *data);
towers_t *my_alloc_towers(towers_t *ptr, size_t new_size, size_t old_size);
planes_t *my_alloc_planes(planes_t *ptr, size_t new_size, size_t old_size);
char **my_str_to_word_array(char const *str, int len_word);
int my_getnbr(char const *str, int stop_value);
float my_getfloat(char const *str, int stop_value);
void manage_event(main_struct_t *data);
void close_window(main_struct_t *data);
void display_assets(main_struct_t *main);
sfSprite *create_sprt(sfTexture *text, char type);
sfRectangleShape *create_rec(sfVector2f pos, sfTexture *text, sfVector2f size,
    sfColor fillColor);
sfCircleShape *create_circle(sfVector2f pos, float radius);
void move_planes(main_struct_t *main);
char *conversion_int_char(int nb);
char *my_strcat(char *dest, char const *src);
quadtree_t *my_alloc_qt(quadtree_t *ptr, size_t new_size, size_t old_size);
int *my_alloc_qt_id(int *ptr, size_t new_size, size_t old_size);
int init_qt(main_struct_t *main);
void check_collisions(main_struct_t *main, quadtree_t qt);
void is_finish(main_struct_t *main, int remove);
#endif /* MY_H */
