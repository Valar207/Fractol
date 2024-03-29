/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:53:44 by vrossi            #+#    #+#             */
/*   Updated: 2019/10/02 13:25:29 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/keyboard_code.h"

void	ft_fill_pix(t_env *e, int x, int y)
{
	int		i;

	i = (((H - (H - y)) * W) - (W - x)) * 4;
	if (x < W && x > 0 && y < H && y > 0)
	{
		if (e->sw == 1)
		{
			e->my_img[i + 0] = (e->color * e->i & 0xFF000000) >> 24;
			e->my_img[i + 1] = (e->color * e->i & 0x00FF0000) >> 16;
			e->my_img[i + 2] = (e->color * e->i & 0x0000FF00) >> 8;
		}
		e->my_img[i + 3] = (e->color & 0x000000FF) >> 0;
	}
}
