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

# include "mlx.h"
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

typedef struct      s_color
{
    int             r1;
    int             r2;
    int             g1;
    int             g2;
    int             b1;
    int             b2;
}                   t_color;

typedef struct		s_img
{
    char            *buf;
    void			*data;
    int				bpp;
    int				size;
    int				endian;
    void			*mlx;
    void			*win;
}					t_img;


typedef struct		s_env
{
    t_img           *w;
    char			**map;
    t_fdf		    **tab;
    int             x;
    int             y;
	int				line;
	int				mod;
	int 			i;
    float           rzoom;
    int             xmax;
	int             ymax;
    int             winx;
    int             winy;
    float           rot;
    float           mrot;
    float           ratio;
    int             anim;
    int             anim2;
    double          rad;
    double          mrad;
    int             col;
    float           cz;
    int             t;
	int				matrix;
    int             config;
    t_fdf             min;
    t_fdf             max;
    t_fdf             up;
    t_color          color;
}					t_env;

void    			init_env(t_env *env);
void    			init_env_step2(t_env *env);
void               init_window(t_img *window);
int                render(t_env *env);
void                pars_map(t_env *env, char *arg);
int					ft_error(char *str);
int					c_to_d(t_env *env, int i);

int		key_hook(int k, t_env *e);
int         expose_hook(t_env *env);
void    ft_end(t_env *env);


#endif
