/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 15:40:53 by tbillard          #+#    #+#             */
/*   Updated: 2017/03/18 18:14:56 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../libft/libft.h"
#include <errno.h>
#include <stdint.h>
#include <math.h>

#define WIN_X   1900
#define WIN_Y   1150
#define CONF_X0 WIN_X - (WIN_X / 7)
#define CONF_YM  WIN_Y / 3
#define NB 20

# define L_C(X, x1, x2, y1, y2) ((int)(((X - x1) * (y2 - y1)) / (x2 - x1)) + y1)
# define L_CF(X, x1, x2, y1, y2) ((float)(((float)((X - x1) * (y2 - y1))) / (float)(x2 - x1)) + y1)

typedef uint32_t Uint32;

typedef struct 				s_coor
{
	int 					x;
	int 					y;
}							t_corr;

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

void		ft_tab_ft_init_1(int (**tab_ft)(t_env*));
void		ft_tab_ft_init_2(int (**tab_ft)(t_env*));
void		ft_tab_ft_init_3(int (**tab_ft)(t_env*));
void		ft_tab_ft_init_4(int (**tab_ft)(t_env*));
void		ft_tab_ft_init_5(int (**tab_ft)(t_env*));


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

int    go_left(t_env *env);
int    go_right(t_env *env);
int    go_top(t_env *env);
int    go_bot(t_env *env);

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

#endif
