#include "panel.h"

static int slide_red(int x, t_env *env, int hit)
{
    int x0;

    x0 = CONF_X0 + MARGE / 2;
    if (hit == 0)
    {
        env->color.r1 += (x - (L_C(env->color.r1, 0, 255, 0, SIZE) + x0));
        if (env->color.r1 > 255)
            env->color.r1 = 255;
        if (env->color.r1 < 0)
            env->color.r1 = 0;
    } 
    else
    {
        env->color.r2 += (x - (L_C(env->color.r2, 0, 255, 0, SIZE) + x0));
        if (env->color.r2 > 255)
            env->color.r2 = 255;
        if (env->color.r2 < 0)
            env->color.r2 = 0;
    }
    return (hit);
}


static int slide_green(int x, t_env *env, int hit)
{
    int x0;

    x0 = CONF_X0 + MARGE / 2;
    if (hit == 2)
    {
        env->color.g1 += (x - (L_C(env->color.g1, 0, 255, 0, SIZE) + x0));
        if (env->color.g1 > 255)
            env->color.g1 = 255;
        if (env->color.g1 < 0)
            env->color.g1 = 0;
    }
    else
    {
        env->color.g2 += (x - (L_C(env->color.g2, 0, 255, 0, SIZE) + x0));
        if (env->color.g2 > 255)
            env->color.g2 = 255;
        if (env->color.g2 < 0)
            env->color.g2 = 0;
    }
    return (hit);
}


static int slide_blue(int x, t_env *env, int hit)
{
    int x0;

    x0 = CONF_X0 + MARGE / 2;
    if (hit == 4)
    {
        env->color.b1 += (x - (L_C(env->color.b1, 0, 255, 0, SIZE) + x0));
        if (env->color.b1 > 255)
            env->color.b1 = 255;
        if (env->color.b1 < 0)
            env->color.b1 = 0;
    }
    else
    {
        env->color.b2 += (x - (L_C(env->color.b2, 0, 255, 0, SIZE) + x0));
        if (env->color.b2 > 255)
            env->color.b2 = 255;
        if (env->color.b2 < 0)
            env->color.b2 = 0;
    }
    return (hit);
}


int      slide_current(int x, t_env *env, int hit)
{
    if (hit == 0 || hit == 1)
        return (slide_red(x, env, hit));
    else if (hit == 2 || hit == 3)
        return (slide_green(x, env, hit));
    else if (hit == 4 || hit == 5)
        return (slide_blue(x, env, hit));
    return (-42);
}
