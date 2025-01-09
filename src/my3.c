/*
** EPITECH PROJECT, 2024
** B-MUL-100 : my_radar
** File description:
** my3.c
*/

#include "../include/my.h"

static char *creation(int i, char *dest, char const *src)
{
    for (int j = 0; src[j] != '\0'; j++){
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

static char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strcat(char *dest, char const *src)
{
    char *str = NULL;

    str = malloc(sizeof(char *) * (my_strlen(dest) + my_strlen(src) + 1));
    if (str == NULL)
        return NULL;
    str = my_strcpy(str, dest);
    for (int i = 0; dest[i] != '\0'; i++){
        if (dest[i + 1] == '\0')
            return creation(i + 1, str, src);
    }
    return NULL;
}

static int is_alphanumeric(char c)
{
    if (c > 47 && c < 58)
        return 1;
    else if ((c > 64 && c < 91) || (c > 96 && c < 123) || c == '.')
        return 1;
    return 0;
}

static int count_words(char const *str)
{
    int value = 1;

    for (int i = 0; str[i] != '\0'; i++)
        if (!is_alphanumeric(str[i]))
            value++;
    return value;
}

static char *add_word(char const *str, int i, int last)
{
    char *dest = NULL;
    int a = 0;

    dest = malloc(sizeof(char) * (i - last + 1));
    if (dest == NULL)
        return NULL;
    for (; last <= i; last++)
        if (is_alphanumeric(str[last])){
            dest[a] = str[last];
            a++;
        }
    dest[a] = '\0';
    return dest;
}

static int find_last_word(char const *str, int i)
{
    while (is_alphanumeric(str[i]))
        i++;
    return i;
}

static void free_all(char **dest, int stop)
{
    for (int i = 0; i < stop; i++)
        free(dest[i]);
    free(dest);
}

char **my_str_to_word_array(char const *str, int len_word)
{
    char **dest = malloc(sizeof(char *) * (count_words(str) + 1));
    int j = 0;
    int last_word = 0;

    if (dest == NULL)
        return NULL;
    for (int i = 0; i != len_word; i++){
        if (!is_alphanumeric(str[i]) && i >= last_word){
            dest[j] = add_word(str, i, last_word);
            last_word = find_last_word(str, i);
            j++;
        }
        if (j > 0 && dest[j - 1] == NULL){
            free_all(dest, j - 1);
            return NULL;
        }
    }
    dest[j] = NULL;
    return dest;
}
