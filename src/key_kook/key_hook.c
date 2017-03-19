/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:17:55 by tbillard          #+#    #+#             */
/*   Updated: 2017/03/18 16:19:19 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define NB1 (Uint32)0b00111111111111100111101011110111
#define NB2 (Uint32)0b00000000001000000110000101000000


static void		ft_tab_ft_init(int (**tab_ft)(t_env*))
{
	int i;

	i = 0;
	while (i < 150)
		tab_ft[i++] = &nil;
	ft_tab_ft_init_1(tab_ft);
	ft_tab_ft_init_2(tab_ft);
}

int				key_hook(SDL_Event k, t_env *e)
{
	static int		(*t_hook[150])(t_env*) = {NULL};
	int             nb;
    static long int d = -42;

    if (k.type != SDL_KEYDOWN)
        return (0);
 	nb = (e->ratio > 10 ? 1 : 50);
	if (!t_hook[0])
		ft_tab_ft_init(t_hook);
    if (d == k.key.keysym.sym)
    {
        d = -42;
        return (0);
    }
    if (k.key.keysym.sym == SDLK_LEFT)
		e->winx += nb;
	else if (k.key.keysym.sym == SDLK_RIGHT)
		e->winx -= nb;
	else if (k.key.keysym.sym == SDLK_DOWN)
		e->winy -= nb;
	else if (k.key.keysym.sym == SDLK_UP)
		e->winy += nb;
	else if (k.key.keysym.sym < 150)
        t_hook[k.key.keysym.sym](e);
    return (0);
}
