#include "utils.h"

t_vec   ft_create_vec(int x, int y)
{
    t_vec   new_vec;

    new_vec.x = x;
    new_vec.y = y;
    return (new_vec);
}

t_vecf   ft_create_vecf(float x, float y)
{
    t_vecf   new_vec;

    new_vec.x = x;
    new_vec.y = y;
    return (new_vec);
}

Color   ft_get_random_color(void) 
{
    return ((Color){
        GetRandomValue(0, 255), 
        GetRandomValue(0, 255), 
        GetRandomValue(0, 255), 
        255
    });
}

//Vec of type int
void    ft_add_vec(t_vec *dest, t_vec *src)
{
    dest->x += src->x;
    dest->y += src->y;
}

void    ft_sub_vec(t_vec *dest, t_vec *src)
{
    dest->x -= src->x;
    dest->y -= src->y;
}

void    ft_mul_vec(t_vec *dest, t_vec *src)
{
    dest->x *= src->x;
    dest->y *= src->y;
}

void    ft_div_vec(t_vec *dest, t_vec *src)
{
    dest->x /= src->x;
    dest->y /= src->y;
}

void    ft_reset_vec(t_vec *vec)
{
    vec->x = 0;
    vec->y = 0;
}

//Vec of type float
void    ft_add_vecf(t_vecf *dest, t_vecf *src)
{
    dest->x += src->x;
    dest->y += src->y;
}

void    ft_sub_vecf(t_vecf *dest, t_vecf *src)
{
    dest->x -= src->x;
    dest->y -= src->y;
}

void    ft_mul_vecf(t_vecf *dest, t_vecf *src)
{
    dest->x *= src->x;
    dest->y *= src->y;
}

void    ft_div_vecf(t_vecf *dest, t_vecf *src)
{
    dest->x /= src->x;
    dest->y /= src->y;
}

void    ft_reset_vecf(t_vecf *vecf)
{
    vecf->x = 0;
    vecf->y = 0;
}