/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:32:37 by tbillard          #+#    #+#             */
/*   Updated: 2017/03/18 15:33:09 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_end(t_env *env)
{
	int i;

	i = 0;
	while (i < env->line)
	{
		free(env->map[i]);
		free(env->tab[i]);
		i++;
	}
	free(env->map);
	free(env->tab);
	free(env->w);
	exit(0);
}
