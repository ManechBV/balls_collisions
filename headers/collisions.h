#ifndef COLLISIONS_H
# define COLLISIONS_H

# include "ball.h"
# include "utils.h"

t_vecf  ft_check_collision_border(t_ball *ball);
void    ft_resolve_collision_border(t_ball *ball, t_vecf coll_vecf);

#endif