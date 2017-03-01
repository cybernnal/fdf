/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 15:40:53 by tbillard          #+#    #+#             */
/*   Updated: 2016/06/19 20:13:54 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
#include <errno.h>

#include "SDL2/SDL.h"
#define WIN_X   1900
#define WIN_Y   1150
#define CONF_X0 WIN_X - (WIN_X / 7)
#define CONF_YM  WIN_Y / 3

# define L_C(X, x1, x2, y1, y2) ((int)(((X - x1) * (y2 - y1)) / (x2 - x1)) + y1)
# define L_CF(X, x1, x2, y1, y2) ((float)(((float)((X - x1) * (y2 - y1))) / (float)(x2 - x1)) + y1)

typedef struct 				s_coor
{
	int 					x;
	int 					y;
}							t_corr;

typedef struct                  s_window
{
    SDL_Window              *window;
    SDL_Event               event;
    SDL_Renderer            *renderer;
    SDL_Texture             *image;
    Uint32                  *img_ptr;
    int                     is_init;
}                           t_window;

typedef float         t_fdf;

typedef struct      s_trace
{
    float           ratio;
    int             z;
    int             zy1;
    int             zx1;
    float           coef;
    float           u;
    float           v;
    float           u1;
    float           v1;
    float           u2;
    float           v2;
    float           rot;
}                   t_trace;

typedef struct		s_env
{
	char			**map;
    t_fdf		    **tab;
    int             x;
    int             y;
	int				line;
	int				mod;
	int 			i;
    float           rzoom;
    int             xmin;
    int             xmax;
	int             ymin;
	int             ymax;
    int             winx;
    int             winy;
    float           rot;
    float           mrot;
    float           ratio;
    float           coefz;
    int             anim;
    int             anim2;
    double          rad;
    double          mrad;
    int             col;
    float           cz;
    int             t;
    int             config;
    t_fdf             min;
    t_fdf             max;
    t_fdf             up;
    t_fdf             down;
}					t_env;

void              init_window2(t_window *window);
void               init_window(t_window *window);
int                render(t_env *env);
void                pars_map(t_env *env, char *arg);
int					ft_error(char *str);
int					c_to_d(t_env *env, int i);
#endif
