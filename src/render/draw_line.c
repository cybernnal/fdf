#include "fdf.h"

static void			ft_tab_ft_init(Uint32 (**tab_ft)(t_env *))
{
    tab_ft[0] = &ign_color;
    tab_ft[1] = &terra_color;
    tab_ft[2] = &map_color;
    tab_ft[3] = &custom_color;
}

static void			loop_line(t_line l, t_env *e,
                                 Uint32 (**t_color)(t_env *), t_window *w)
{
    int i;

    i = 0;
    l.color = t_color[e->col](e);
    l.dx = abs(l.x1 - l.x0);
    l.sx = l.x0 < l.x1 ? 1 : -1;
    l.dy = abs(l.y1 - l.y0);
    l.sy = l.y0 < l.y1 ? 1 : -1;
    l.err = (l.dx > l.dy ? l.dx : -l.dy) / 2;
    while (1)
    {
        l.color = custom_color_il(e, l.color, i);//Uint32)L_CF(i, 0, e->ratio, l.color, t_color[e->col + 1](e));
        draw_pixel(l.x0, l.y0, l.color, w);
        if (l.x0 == l.x1 && l.y0 == l.y1)
            break ;
        l.e2 = l.err;
        if (l.e2 > -l.dx)
        {
            l.err -= l.dy;
            l.x0 += l.sx;
        }
        if (l.e2 < l.dy)
        {
            l.err += l.dx;
            l.y0 += l.sy;
        }
        i++;
    }
}

static void			line(t_line l, t_env *e, t_window *w)
{
    static Uint32	(*t_color[6])(t_env *) = {NULL};

    if (!t_color[0])
        ft_tab_ft_init(t_color);
    if (e->t && (l.y0 > WIN_Y || l.x0 > WIN_X || l.x0 < 0
                 || l.y0 < 0 || l.y1 > WIN_Y ||
                 l.x1 > WIN_X || l.x1 < 0 || l.y1 < 0))
        return ;
    loop_line(l, e, t_color, w);
}


void			call_line(t_trace t, t_env *env, t_window *w, int nb)
{
    t_line		l;

    l.x0 = (int)((t.u + env->winx) * t.coef);
    l.y0 = (int)((t.v + env->winy + t.z * env->cz) * t.coef);
    if (nb == 0 || nb == 1)
    {
        env->pos = 1;
        l.x1 = (int)(((t.u1 + env->winx) * t.coef));
        l.y1 = (int)((t.v1 + env->winy + t.zx1 * env->cz) * t.coef);
        line(l, env, w);
    }
    if (nb == 0 || nb == 2)
    {
        env->pos = 2;
        l.x1 = (int)((t.u2 + env->winx) * t.coef);
        l.y1 = (int)(((t.v2 + env->winy + t.zy1 * env->cz) * t.coef));
        line(l, env, w);
    }
}
