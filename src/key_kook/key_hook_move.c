/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:20:05 by tbillard          #+#    #+#             */
/*   Updated: 2017/03/18 16:21:41 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		go_left(t_env *env)
{
	int nb;

	nb = (env->ratio > 10 ? 1 : 50);
	env->winx += nb;
	return (0);
}

int		go_right(t_env *env)
{
	int nb;

	nb = (env->ratio > 10 ? 1 : 50);
	env->winx -= nb;
	return (0);
}

int		go_top(t_env *env)
{
	int nb;

	nb = (env->ratio > 10 ? 1 : 50);
	env->winy += nb;
	return (0);
}

int		go_bot(t_env *env)
{
	int nb;

	nb = (env->ratio > 10 ? 1 : 50);
	env->winy -= nb;
	return (0);
}
