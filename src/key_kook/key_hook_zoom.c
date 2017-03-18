/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_zoom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:24:33 by tbillard          #+#    #+#             */
/*   Updated: 2017/03/18 16:24:55 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		zoom_in(t_env *env)
{
	env->ratio += env->rzoom;
	return (0);
}

int		zoom_out(t_env *env)
{
	if (env->ratio - env->rzoom > 0)
		env->ratio -= env->rzoom;
	return (0);
}

int		zoom_p(t_env *env)
{
	env->rzoom += 0.1;
	return (0);
}

int		zoom_m(t_env *env)
{
	if (env->rzoom - 0.1 > 0)
		env->rzoom -= 0.1;
	return (0);
}
