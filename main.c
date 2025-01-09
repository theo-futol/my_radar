/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** main.c
*/

#include "include/my.h"

static int my_dprintf(char *str)
{
    write(2, str, my_strlen(str));
    return 84;
}

static int display_help(void)
{
    int error = 0;

    error += my_putstr("Air traffic simulation panel\n") == -1 ? 1 : 0;
    error += my_putstr("USAGE\n") == -1 ? 84 : 0;
    error += my_putstr(" ./my_radar [OPTIONS] path_to_script\n") == -1 ? 1 : 0;
    error += my_putstr("   path_to_script   The path to the script file.\n") ==
    -1 ? 1 : 0;
    error += my_putstr("OPTIONS\n") == -1 ? 1 : 0;
    error += my_putstr(" -h               print the usage and quit.\n") == -1 ?
    1 : 0;
    error += my_putstr("USER INTERACTIONS\n") == -1 ? 1 : 0;
    error += my_putstr(" 'L' key       enable/disable hitboxes and areas.\n")
    == -1 ? 1 : 0;
    error += my_putstr(" 'S' key       enable/disable sprites.\n") == -1 ? 1 :
    0;
    return error > 0 ? 84 : 0;
}

static int init_texture(main_struct_t *data)
{
    data->wind.bg_txt = sfTexture_createFromFile("ressources/img/bg.png", NULL
    );
    data->wind.tower_txt = sfTexture_createFromFile("ressources/img/tower.png",
    NULL);
    data->wind.plane_txt = sfTexture_createFromFile("ressources/img/plane.png",
    NULL);
    if (data->wind.bg_txt == NULL || data->wind.tower_txt == NULL ||
        data->wind.plane_txt == NULL)
        return 84;
    return 0;
}

static int init_sprite(main_struct_t *data)
{
    data->wind.bg_sprt = sfSprite_create();
    sfSprite_setTexture(data->wind.bg_sprt, data->wind.bg_txt, sfTrue);
    if (data->wind.bg_sprt == NULL)
        return 84;
    return 0;
}

static int init_sound(main_struct_t *data)
{
    data->wind.sound = sfMusic_createFromFile("ressources/sound/music.ogg");
    if (data->wind.sound == NULL)
        return 84;
    sfMusic_play(data->wind.sound);
    sfMusic_setLoop(data->wind.sound, sfTrue);
    return 0;
}

static int init_txt(main_struct_t *data)
{
    data->wind.font = sfFont_createFromFile("ressources/font/arial.ttf");
    if (data->wind.font == NULL)
        return 84;
    data->wind.text = sfText_create();
    if (data->wind.text == NULL)
        return 84;
    sfText_setString(data->wind.text, "0:0");
    sfText_setFont(data->wind.text, data->wind.font);
    sfText_setCharacterSize(data->wind.text, 40);
    sfText_setPosition(data->wind.text, (sfVector2f){1830, 10});
    sfText_setColor(data->wind.text, sfBlack);
    return 0;
}

static int init_struct(main_struct_t *data)
{
    data->wind.my_clock = sfClock_create();
    if (data->wind.my_clock == NULL || init_texture(data) == 84 || init_sprite(
        data) == 84 || init_sound(data) == 84 || init_txt(data) == 84)
        return 84;
    data->all_planes = NULL;
    data->all_towers = NULL;
    data->wind.mode.width = 1920;
    data->wind.mode.height = 1080;
    data->wind.mode.bitsPerPixel = 32;
    data->len_planes = 0;
    data->planes_avail = 0;
    data->len_towers = 0;
    data->display_qt = 1;
    data->display_sprt = 1;
    data->wind.wind = sfRenderWindow_create(data->wind.mode, "MyRadar",
    sfResize | sfClose, NULL);
    if (data->wind.wind == NULL)
        return 84;
    sfRenderWindow_setFramerateLimit(data->wind.wind, 60);
    return 0;
}

static int my_radar(char *path)
{
    main_struct_t main = {0};

    if (init_struct(&main) == 84 || parsing_file(path, &main) == 84){
        close_window(&main);
        return 84;
    }
    for (; sfRenderWindow_isOpen(main.wind.wind); manage_event(&main)){
        move_planes(&main);
        if (init_qt(&main) == 84)
            return 84;
        for (int i = 0; i < main.len_qt; i++)
            check_collisions(&main, main.my_qt[i]);
        display_assets(&main);
    }
    close_window(&main);
    return 0;
}

void is_finish(main_struct_t *main, int remove)
{
    main->planes_avail -= remove;
    if (main->planes_avail <= 0)
        sfRenderWindow_close(main->wind.wind);
}

int main(int argc, char **argv)
{
    if (argc <= 1 || argc > 2)
        return my_dprintf("./my_radar: bad arguments: retry with -h\n");
    if (argc == 2){
        if (my_strcmp(my_strlowcase(argv[1]), "-h") == 0)
            return display_help();
        else
            return my_radar(argv[1]);
    }
}
