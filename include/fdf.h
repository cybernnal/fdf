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
#define WIN_WIDTH   1100
#define WIN_HEIGHT  1100

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

typedef struct		s_env
{
	char			**map;
    t_fdf		    *tab;
	Uint32 			*color;
	int				line;
	int				mod;
	int 			i;
    int             zoom;
    int             xmin;
    int             xmax;
	int             ymin;
	int             ymax;
    t_fdf             min;
    t_fdf             max;
    t_fdf             up;
    t_fdf             down;
}					t_env;

void                init_window(t_window *window);
int                render(t_env *env);
void                pars_map(t_env *env, char *arg);
int					ft_error(char *str);
int					c_to_d(t_env *env);
#endif
