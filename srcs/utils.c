#include "utils.h"

t_vec   ft_create_vec(int x, int y)
{
    t_vec   new_vec;

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
