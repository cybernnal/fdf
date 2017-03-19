#include "panel.h"

void drawcircle(t_corr c, int radius, Uint32 color, t_window *w)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        draw_pixel(c.x + x, c.y + y, color, w);
        draw_pixel(c.x + y, c.y + x, color, w);
        draw_pixel(c.x - y, c.y + x, color, w);
        draw_pixel(c.x - x, c.y + y, color, w);
        draw_pixel(c.x - x, c.y - y, color, w);
        draw_pixel(c.x - y, c.y - x, color, w);
        draw_pixel(c.x + y, c.y - x, color, w);
        draw_pixel(c.x + x, c.y - y, color, w);

        y += 1;
        err += 1 + 2*y;
        if (2*(err-x) + 1 > 0)
        {
            x -= 1;
            err += 1 - 2*x;
        }
    }
}