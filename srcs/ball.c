#include <stdlib.h>
#include <math.h>

#include "raylib.h"
#include "ball.h"
#include "utils.h"
#include "collisions.h"

//Creates a ball and return its pointer
t_ball  *ft_create_ball(int x, int y, float radius)
{
    t_ball  *new_ball;

    new_ball = malloc(sizeof(t_ball));
    if (!new_ball)
        return (NULL);
    
    new_ball->pos = ft_create_vecf((float)x, (float)y);
    new_ball->radius = radius;

    float   rotation = (2 * PI) / 32; 
    rotation *= (float)GetRandomValue(0, 32);
    
    new_ball->dir = ft_create_vecf(cosf(rotation), sinf(rotation));
    new_ball->vel = 1.0;
    new_ball->p_next = NULL;
    new_ball->color = ft_get_random_color();
    return (new_ball);
}

//Init an already existing ball manager via its pointer
void  ft_init_ball_manager(t_ball_manager *ball_m)
{
    ball_m->size = 0;
    ball_m->p_balls = NULL;
}

//Duh
void    ft_draw_ball(t_ball *ball)
{
    DrawCircle(ball->pos.x, ball->pos.y, ball->radius, ball->color);
}

//Add a ball at the beginning of the chained list
void    ft_add_ball_to_chain(t_ball_manager *ball_m, int x, int y, float radius)
{
    t_ball  *new_ball;

    new_ball = ft_create_ball(x, y, radius);
    if (!new_ball)
        return ;

    new_ball->p_next = ball_m->p_balls;
    ball_m->p_balls = new_ball;
    ball_m->size++;
}

void    ft_update_balls(t_ball_manager *ball_m)
{
    t_ball  *current;

    current = ball_m->p_balls;
    while (current)
    {
        ft_check_and_resolve_border_collision(current);
        
        //Reset move vector to 0, 0
        ft_reset_vecf(&(current->move_vecf));

        //Apply dir and vel to move_vecf
        ft_add_vecf(&(current->move_vecf), &(current->dir));
        current->move_vecf.x *= current->vel;
        current->move_vecf.y *= current->vel;

        //Update position based on move_vecf
        ft_add_vecf(&(current->pos), &(current->move_vecf));

        //Loop through the next ball
        current = current->p_next;
    }
}

//Duh
void    ft_draw_all_balls(t_ball_manager *ball_m)
{
    t_ball  *current;

    //current is used to avoid changing the original pointer
    //ps: that's putain de logique bordel
    current = ball_m->p_balls;
    while (current)
    {
        DrawCircle(current->pos.x, current->pos.y, current->radius, current->color);
        current = current->p_next;
    }
}

//Nique les mallocs ces fils de putes
void    ft_free_ball_manager(t_ball_manager *ball_m)
{
    t_ball  *current;

    current = ball_m->p_balls;
    while (current)
    {
        t_ball  *tmp = current;
        current = current->p_next;
        free(tmp);
    }
    ball_m->p_balls = NULL;
    ball_m->size = 0;
}