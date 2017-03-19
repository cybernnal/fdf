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
	tab_ft[28] = &gt_p;
	tab_ft[29] = &bo_p;
	tab_ft[38] = &rov_d;
	tab_ft[40] = &rov_i;
	tab_ft[45] = &ro_d;
	tab_ft[46] = &ro_i;
	tab_ft[53] = &ft_exit;
	tab_ft[123] = &go_left;
	tab_ft[124] = &go_right;
	tab_ft[125] = &go_bot;
	tab_ft[126] = &go_top;
}

void		ft_tab_ft_init_1(int (**tab_ft)(t_env*))
{
	tab_ft[0] = &zoom_out;
	tab_ft[1] = &zoom_m;
	tab_ft[2] = &opti;
	tab_ft[4] = &rtv_i;
	tab_ft[5] = &rtv_d;
	tab_ft[6] = &zoom_in;
	tab_ft[7] = &zoom_p;
	tab_ft[9] = &rt_d;
	tab_ft[11] = &rt_i;
	tab_ft[12] = &c_color;
	tab_ft[13] = &zo_i;
	tab_ft[14] = &zo_d;
	tab_ft[17] = &matrix_hook;
	tab_ft[18] = &ro_m;
	tab_ft[19] = &ro_p;
	tab_ft[20] = &rt_m;
	tab_ft[21] = &rt_p;
	tab_ft[22] = &go_p;
	tab_ft[23] = &go_m;
	tab_ft[24] = &bt_p;
	tab_ft[25] = &bo_m;
	tab_ft[26] = &gt_m;
	tab_ft[27] = &bt_m;
}
