/*
** EPITECH PROJECT, 2021
** backrooms.h
** File description:
** backrooms
*/

#ifndef BACKROOMS_H_
    #define BACKROOMS_H_
    #define UNUSED(x) (void)(x)
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>

/*** STRUCT ***/
typedef struct text_s {
    sfText *clip;
    sfText *welcome;
    sfText *escape;
} text_t;

typedef struct clocks_s {
    sfClock *main_clock;
    float main_seconds;
    sfClock *escape_clock;
    float escape_seconds;
} clocks_t;

typedef struct sound_s {
    sfSound *sound;
    sfSoundBuffer *buffer;
    bool is_playing;
} sound_t;

typedef struct backrooms_s {
    sfRenderWindow *window;
    clocks_t *clocks;
    sfEvent event;
    text_t *text;
    sound_t *sound;
    sfSprite *sprite;
} backrooms_t;

/*** BASIC FUNCTIONS ***/
int error_handling(int ac, char **av);
int backrooms(int ac, char **av);
float update_clock(sfClock *clock);

/*** DISPLAY FUNCTIONS ***/
void display_escape(backrooms_t *backrooms);
void display_steps(backrooms_t *backrooms);

/*** STRUCT FUNCTIONS ***/
backrooms_t *init_backrooms_struct(void);
sfRenderWindow *init_window(void);
clocks_t *init_clock_struct(void);
sound_t *init_sound(char *path);
text_t *init_texts_struct(void);
sfSprite *init_sprite(char *path);
void free_struct(backrooms_t *backrooms);

#endif/*BACKROOMS_H_*/
