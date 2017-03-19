#include "fdf.h"

void			matrix(t_trace *t, t_env *env)
{
    t->u = env->x * cosf(t->rot) + env->y * cosf((t->rot + env->rad));
    t->v = env->x * sinf(t->rot) + env->y * sinf((t->rot + env->rad));
    t->u1 = (env->x + 1) * cosf(t->rot) + env->y * cosf((t->rot + env->rad));
    t->v1 = (env->x + 1) * sinf(t->rot) + env->y * sinf((t->rot + env->rad));
    t->u2 = env->x * cosf(t->rot) + (env->y + 1) * cosf((t->rot + env->rad));
    t->v2 = env->x * sinf(t->rot) + (env->y + 1) * sinf((t->rot + env->rad));
}

void			matrix2(t_trace *t, t_env *env)
{
    t->u = env->x;
    t->v = env->y;
    t->u1 = env->x + 1;
    t->u2 = env->x;
    t->v1 = env->y;
    t->v2 = env->y + 1;
}

void			ft_matrix_ft_init(void (**tab_ft)(t_trace *, t_env *))
{
    tab_ft[1] = &matrix;
    tab_ft[0] = &matrix2;
}