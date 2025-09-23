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

//utils.c
t_vec   ft_create_vec(int x, int y);
t_vecf  ft_create_vecf(float x, float y);
Color   ft_get_random_color(void);

void    ft_add_vec(t_vec *dest, t_vec *src);
void    ft_sub_vec(t_vec *dest, t_vec *src);
void    ft_mul_vec(t_vec *dest, t_vec *src);
void    ft_div_vec(t_vec *dest, t_vec *src);
void    ft_reset_vec(t_vec *vec);

void    ft_add_vecf(t_vecf *dest, t_vecf *src);
void    ft_sub_vecf(t_vecf *dest, t_vecf *src);
void    ft_mul_vecf(t_vecf *dest, t_vecf *src);
void    ft_div_vecf(t_vecf *dest, t_vecf *src);
void    ft_reset_vecf(t_vecf *vecf);

#endif //UTILS_H