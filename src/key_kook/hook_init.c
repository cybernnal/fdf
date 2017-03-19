/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:16:40 by tbillard          #+#    #+#             */
/*   Updated: 2017/03/18 16:17:38 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void		ft_tab_ft_init_2(int (**tab_ft)(t_env*))
{
	tab_ft['8'] = &gt_p;
	tab_ft['0'] = &bo_p;
	tab_ft['j'] = &rov_d;
	tab_ft['k'] = &rov_i;
	tab_ft['n'] = &ro_d;
	tab_ft['m'] = &ro_i;
    tab_ft['o'] = &anim_ra;
    tab_ft['p'] = &anim_ro;
    tab_ft['c'] = &config_set;
	tab_ft[SDLK_ESCAPE] = &ft_exit;
}

void		ft_tab_ft_init_1(int (**tab_ft)(t_env*))
{
	tab_ft['a'] = &zoom_out;
	tab_ft['s'] = &zoom_m;
	tab_ft['d'] = &opti;
	tab_ft['h'] = &rtv_i;
	tab_ft['g'] = &rtv_d;
	tab_ft['z'] = &zoom_in;
	tab_ft['x'] = &zoom_p;
	tab_ft['v'] = &rt_d;
	tab_ft['b'] = &rt_i;
	tab_ft['q'] = &c_color;
	tab_ft['w'] = &zo_i;
	tab_ft['e'] = &zo_d;
	tab_ft['t'] = &matrix_hook;
	tab_ft['1'] = &ro_m;
	tab_ft['2'] = &ro_p;
	tab_ft['3'] = &rt_m;
	tab_ft['4'] = &rt_p;
	tab_ft['6'] = &go_p;
	tab_ft['5'] = &go_m;
	tab_ft['='] = &bt_p;
	tab_ft['9'] = &bo_m;
	tab_ft['7'] = &gt_m;
	tab_ft['-'] = &bt_m;
}
