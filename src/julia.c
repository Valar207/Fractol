/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:18:17 by vrossi            #+#    #+#             */
/*   Updated: 2019/10/02 12:56:46 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/keyboard_code.h"
#include <math.h>

void	julia(t_env *e)
{
	e->y = 0;
	while (e->y < H)
	{
		e->x = 0;
		while (e->x < W)
		{
			e->nr = 1.5 * (e->x - W / 2) / (0.5 * e->zoom * W) + e->mx;
			e->ni = (e->y - H / 2) / (0.5 * e->zoom * H) + e->my;
			e->i = 0;
			while (e->i < e->maxit && (e->nr * e->nr + e->ni * e->ni) < 4)
			{
				e->or = e->nr;
				e->oi = e->ni;
				e->nr = e->or * e->or - e->oi * e->oi + e->cr;
				e->ni = 2 * e->or * e->oi + e->ci;
				e->i++;
				color(e);
			}
			ft_fill_pix(e, e->x, e->y);
			e->x++;
		}
		e->y++;
	}
}
