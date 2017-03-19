#include "panel.h"

static Uint32       get_color(int c, int i, int x0, int x1)
{
    Uint32 color;

     color = (Uint32)(int)L_CF(i, 0, SIZE, 0, 255);
    if (c == 0)
        return ((Uint32)(color << 16));
    if (c == 1)
        return ((Uint32)(color << 8));
    if (c == 2)
        return ((Uint32)(color));
    return (0);
}

static void			loop_line(t_line l, t_env *e, t_window *w, int c)
{
    int i;

    i = 0;
    l.dx = abs(l.x1 - l.x0);
    l.sx = l.x0 < l.x1 ? 1 : -1;
    l.dy = abs(l.y1 - l.y0);
    l.sy = l.y0 < l.y1 ? 1 : -1;
    l.err = (l.dx > l.dy ? l.dx : -l.dy) / 2;
    while ((l.color = get_color(c, i++, l.x0, l.x1)) || 1)
    {
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
    }
}

void			l2(t_line l, t_env *e, t_window *w, int c)
{
    if (e->t && (l.y0 > WIN_Y || l.x0 > WIN_X || l.x0 < 0
                 || l.y0 < 0 || l.y1 > WIN_Y ||
                 l.x1 > WIN_X || l.x1 < 0 || l.y1 < 0))
        return ;
    loop_line(l, e, w, c);
}