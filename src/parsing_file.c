/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** parsing_file.c
*/

#include "../include/my.h"

static void calcul_angle(planes_t *plane)
{
    plane->angle = atan2f(plane->arrival.y - plane->departure.y,
    plane->arrival.x - plane->departure.x);
    plane->is_avail = sfFalse;
    sfRectangleShape_setRotation(plane->rec, 45 * plane->angle);
}

static int is_valid_plane(char **array)
{
    for (int i = 1; i < 7; i++)
        if (array[i] == NULL)
            return 84;
    return 0;
}

static int is_valid_tower(char **array)
{
    for (int i = 1; i < 4; i++)
        if (array[i] == NULL)
            return 84;
    return 0;
}

static int add_to_list_plane(main_struct_t *data, char **array)
{
    int len = data->len_planes;

    if (is_valid_plane(array) == 84)
        return 84;
    data->all_planes = my_alloc_planes(data->all_planes, len + 1, len);
    if (data->all_planes == NULL)
        return 84;
    data->all_planes[len].departure.x = my_getfloat(array[1], -1);
    data->all_planes[len].departure.y = my_getfloat(array[2], -1);
    data->all_planes[len].pos = data->all_planes[len].departure;
    data->all_planes[len].arrival.x = my_getfloat(array[3], -1);
    data->all_planes[len].arrival.y = my_getfloat(array[4], -1);
    data->all_planes[len].speed = my_getfloat(array[5], -1);
    data->all_planes[len].delay = my_getfloat(array[6], -1);
    data->all_planes[len].rec = create_rec(data->all_planes[len].pos, data->
    wind.plane_txt, (sfVector2f){20.0, 20.0}, sfWhite);
    if (data->all_planes[len].rec == NULL)
        return 84;
    calcul_angle(&data->all_planes[len]);
    return 0;
}

static int add_to_list_tower(main_struct_t *data, char **array)
{
    int len = data->len_towers;

    if (is_valid_tower(array) == 84)
        return 84;
    data->all_towers = my_alloc_towers(data->all_towers, len + 1, len);
    if (data->all_towers == NULL)
        return 84;
    data->all_towers[len].pos.x = my_getfloat(array[1], -1);
    data->all_towers[len].pos.y = my_getfloat(array[2], -1);
    data->all_towers[len].radius = my_getfloat(array[3], -1);
    data->all_towers[len].tower_sprt = create_sprt(data->wind.tower_txt, 'T');
    data->all_towers[len].circle = create_circle(data->all_towers[len].pos,
    data->all_towers[len].radius);
    if (data->all_towers[len].tower_sprt == NULL || data->all_towers[len].
        circle == NULL)
        return 84;
    sfSprite_setPosition(data->all_towers[len].tower_sprt, data->all_towers
    [len].pos);
    return 0;
}

static int add_to_list(main_struct_t *data, char *line, char **array)
{
    if (array == NULL || (line[0] != 'A' && line[0] != 'T'))
        return 84;
    if (line[0] == 'A'){
        if (add_to_list_plane(data, array) == 84)
            return 84;
        else {
            data->planes_avail++;
            data->len_planes++;
            return 0;
        }
    }
    if (line[0] == 'T'){
        if (add_to_list_tower(data, array) == 84)
            return 84;
        else {
            data->len_towers++;
            return 0;
        }
    }
    return 84;
}

static void free_all(char *line, FILE *stream, char **array)
{
    free(line);
    fclose(stream);
    if (array != NULL){
        for (int i = 0; array[i] != NULL; i++)
            free(array[i]);
        free(array);
    }
}

static int open_file(char *path, main_struct_t *data)
{
    FILE *stream = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    char **array = NULL;

    if (stream == NULL)
        return 84;
    for (ssize_t byte = getline(&line, &len, stream); byte != -1; byte =
        getline(&line, &len, stream)){
        if (line == NULL){
            fclose(stream);
            return 84;
        }
        array = my_str_to_word_array(line, my_strlen(line) + 1);
        if (array == NULL || add_to_list(data, line, array) == 84){
            free_all(line, stream, array);
            return 84;
        }
    }
    free_all(line, stream, array);
    return 0;
}

int parsing_file(char *path, main_struct_t *main)
{
    if (open_file(path, main) == 84)
        return 84;
    return 0;
}
