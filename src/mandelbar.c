/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:18:17 by vrossi            #+#    #+#             */
/*   Updated: 2019/10/02 12:55:04 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/keyboard_code.h"
#include <math.h>

void	mandelbar_bis(t_env *e)
{
	e->or = e->nr;
	e->oi = e->ni;
	e->nr = e->or * (e->or * e->or * e->or * e->or - 10 * e->oi * \
			e->oi * e->or * e->or \
			+ 5 * e->oi * e->oi * e->oi * e->oi) + e->pr;
	e->ni = -e->ni * (5 * e->or * e->or * e->or * e->or \
			- 10 * e->oi * e->oi * e->or * e->or + e->oi * e->oi * e->oi * \
			e->oi) + e->pi;
	e->i++;
	color(e);
}

void	mandelbar(t_env *e)
{
	e->y = 0;
	while (e->y < H)
	{
		e->x = 0;
		while (e->x < W)
		{
			e->pr = 1.5 * (e->x - W / 2) / (0.5 * e->zoom * W) + e->mx;
			e->pi = (e->y - H / 2) / (0.5 * e->zoom * H) + e->my;
			e->nr = 0;
			e->ni = 0;
			e->i = 0;
			while (e->i < e->maxit && (e->nr * e->nr + e->ni * e->ni) < 4)
			{
				mandelbar_bis(e);
			}
			ft_fill_pix(e, e->x, e->y);
			e->x++;
		}
		e->y++;
	}
}
