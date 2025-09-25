#include "collisions.h"

void    ft_check_and_resolve_border_collision(t_ball *ball)
{
    if (ball->pos.x + ball->radius > GetScreenWidth())
    {
        ball->dir.x *= -1;
        ball->pos.x = GetScreenWidth() - ball->radius;
    }
    if (ball->pos.y + ball->radius > GetScreenHeight())
    {
        ball->dir.y *= -1;
        ball->pos.y = GetScreenHeight() - ball->radius;
    }
    if (ball->pos.x - ball->radius < 0)
    {
        ball->dir.x *= -1;
        ball->pos.x = ball->radius;
    }
    if (ball->pos.y - ball->radius < 0)
    {
        ball->dir.y *= -1;
        ball->pos.y = ball->radius;
    }
}