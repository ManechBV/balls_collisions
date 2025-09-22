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

//utils.h
t_vec   ft_create_vec(int x, int y);
Color   ft_get_random_color(void);

#endif //UTILS_H