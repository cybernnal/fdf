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
#define CONF_X0 (WIN_X - (WIN_X / 7))
#define CONF_YM  (WIN_Y / 4)
#define NB 20

# define L_C(X, x1, x2, y1, y2) ((int)(((X - x1) * (y2 - y1)) / (x2 - x1)) + y1)
# define L_CF(X, x1, x2, y1, y2) ((float)(((float)((X - x1) * (y2 - y1))) / (float)(x2 - x1)) + y1)

typedef float         t_fdf;


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


typedef struct 				s_line
{
    int 					x0;
    int 					x1;
    int 					y0;
    int 					y1;
    int						dx;
    int						sx;
    int						dy;
    int						sy;
    int						err;
    int						e2;
    Uint32					color;
}							t_line;

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
void               init_window(t_window *window);
int                render(t_env *env);
void                pars_map(t_env *env, char *arg);
int					ft_error(char *str);
int					c_to_d(t_env *env, int i);

int		key_hook(SDL_Event k, t_env *e);
void    ft_end(t_env *env);

void		ft_tab_ft_init_1(int (**tab_ft)(t_env*));
void		ft_tab_ft_init_2(int (**tab_ft)(t_env*));

void draw_pixel(int x, int y, Uint32 color, t_window *w);

int         matrix_hook(t_env *env);
int         ft_exit(t_env *env);
int          c_color(t_env *env);
int     opti(t_env *env);
int     nil(t_env *env);

int     zo_i(t_env *env);
int     zo_d(t_env *env);

int     rt_i(t_env *env);
int     rt_d(t_env *env);
int     rtv_i(t_env *env);
int     rtv_d(t_env *env);

int    zoom_in(t_env *env);
int    zoom_out(t_env *env);
int    zoom_p(t_env *env);
int    zoom_m(t_env *env);

int     ro_i(t_env *env);
int     ro_d(t_env *env);
int     rov_i(t_env *env);
int     rov_d(t_env *env);

int     ro_m(t_env *env);
int     ro_p(t_env *env);
int     rt_m(t_env *env);
int     rt_p(t_env *env);

int     go_m(t_env *env);
int     go_p(t_env *env);
int     gt_m(t_env *env);
int     gt_p(t_env *env);

int     bo_m(t_env *env);
int     bo_p(t_env *env);
int     bt_m(t_env *env);
int     bt_p(t_env *env);



Uint32		terra_color(t_env *e);
Uint32		map_color(t_env *env);
Uint32		custom_color(t_env *env);
Uint32		ign_color(t_env *e);


void			call_line(t_trace t, t_env *env, t_window *w, int nb);


void			matrix(t_trace *t, t_env *env);
void			matrix2(t_trace *t, t_env *env);
void			ft_matrix_ft_init(void (**tab_ft)(t_trace *, t_env *));


int		anim_ra(t_env *env);
int		anim_ro(t_env *env);
void    render_conf(t_window *w, t_env *env);
int		config_set(t_env *env);

#endif
