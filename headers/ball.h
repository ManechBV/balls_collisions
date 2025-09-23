#ifndef BALL_H
# define BALL_H

#include "utils.h"

typedef struct  s_ball
{
    t_vecf          pos;
    t_vecf          dir;
    t_vecf          move_vecf;
    float           radius;
    float           vel;
    Color           color;
    struct s_ball   *p_next;
} t_ball;

typedef struct  s_ball_manager
{
    int     size;
    t_ball  *p_balls;
} t_ball_manager;

//ball.c
t_ball          *ft_create_ball(int x, int y, float radius);
void            ft_draw_ball(t_ball *ball);

void            ft_init_ball_manager(t_ball_manager *ball_m);
void            ft_free_ball_manager(t_ball_manager *ball_m);
void            ft_add_ball_to_chain(t_ball_manager *ball_m, int x, int y, float radius);
void            ft_draw_all_balls(t_ball_manager *ball_m);

void            ft_update_balls(t_ball_manager *ball_m);

#endif //BALL_H