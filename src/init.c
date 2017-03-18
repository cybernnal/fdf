/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:30:01 by tbillard          #+#    #+#             */
/*   Updated: 2017/03/18 15:30:55 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_img *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "fdf");
	e->data = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->buf = mlx_get_data_addr(
			e->data,
			&e->bpp,
			&e->size,
			&e->endian);
}
