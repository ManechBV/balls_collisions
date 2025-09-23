#include "collisions.h"
#include "raylib.h"

t_vecf  ft_check_collision_border(t_ball *ball)
{
    t_vecf  normal_vecf;

    normal_vecf = ft_create_vecf(0.0, 0.0);

    //Check right border
    if (ball->pos.x + ball->radius > GetScreenWidth())
    {
        normal_vecf.x = -1.0;
        return (normal_vecf);
    }
    //Check left border
    if (ball->pos.x - ball->radius < 0)
    {
        normal_vecf.x = 1.0;
        return (normal_vecf);
    }
    //Check down border
    if (ball->pos.y + ball->radius > GetScreenHeight())
    {
        normal_vecf.y = -1.0;
        return (normal_vecf);
    }
    //Check top border
    if (ball->pos.y - ball->radius < 0)
    {
        normal_vecf.y = 1.0;
        return (normal_vecf);
    }

    return (normal_vecf);
}

void    ft_resolve_collision_border(t_ball *ball, t_vecf coll_vecf)
{
    if (coll_vecf.x == 1.0)
        ball->pos.x = ball->radius;
    if (coll_vecf.x == -1.0)
        ball->pos.x = (float)GetScreenWidth() - ball->radius;

    if (coll_vecf.y == 1.0)
        ball->pos.y = ball->radius;
    if (coll_vecf.y == -1.0)
        ball->pos.y = (float)GetScreenHeight() - ball->radius;

    ft_mul_vecf(&coll_vecf, &(ball->dir));
    ball->dir.x += coll_vecf.x * 2;
    ball->dir.y += coll_vecf.y * 2;
    //ft_add_vecf(&(ball->dir), &coll_vecf);
}



