#ifndef UTILS_H
# define UTILS_H

# define DEFAULT_WINDOW_WIDTH 800
# define DEFAULT_WINDOW_HEIGHT 600

# include <stdlib.h>

# include "raylib.h"

typedef struct  s_vec
{
    int x;
    int y;
} t_vec;

typedef struct  s_vecf
{
    float x;
    float y;
} t_vecf;

//utils.h
t_vec   ft_create_vec(int x, int y);
t_vecf  ft_create_vecf(float x, float y);
Color   ft_get_random_color(void);

#endif //UTILS_H