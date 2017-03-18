/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_green_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:16:05 by tbillard          #+#    #+#             */
/*   Updated: 2017/03/18 16:16:20 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		go_m(t_env *env)
{
	if (env->color.g1 - NB > 0)
		env->color.g1 -= NB;
	return (0);
}

int		go_p(t_env *env)
{
	if (env->color.g1 + NB < 255)
		env->color.g1 += NB;
	return (0);
}

int		gt_m(t_env *env)
{
	if (env->color.g2 - NB > 0)
		env->color.g2 -= NB;
	return (0);
}

int		gt_p(t_env *env)
{
	if (env->color.g2 + NB < 255)
		env->color.g2 += NB;
	return (0);
}
