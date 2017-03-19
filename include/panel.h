//
// Created by tom billard on 19/03/2017.
//

#ifndef FDF_PANEL_H
#define FDF_PANEL_H

#include "fdf.h"

#define MARGE   30
#define SIZE    ((WIN_X - CONF_X0) - MARGE)
#define BT      (CONF_YM / 3)
#define CUR_S   7
#define RED     0xff0000
#define GREEN   0x00ff00
#define BLUE    0x0000ff

void			l2(t_line l, t_env *e, t_window *w, int c);
void        draw_all_slide(t_window *w, t_env *e);
void    drawcircle(t_corr c, int radius, Uint32 color, t_window *w);
void        draw_all_curs(t_env *env, t_window *w);
void      mouse_hit(t_env *env);
int      slide_current(int x, t_env *env, int hit);


#endif //FDF_PANEL_H
