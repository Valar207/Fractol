/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:53:44 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/17 14:56:47 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/keyboard_code.h"

void	ft_fill_pix(t_env *e, int x, int y)
{
	int		i;

	i = (((HEIGHT - (HEIGHT - y)) * WIDTH) - (WIDTH - x)) * 4;
	if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
	{
		e->my_img[i + 0] = (e->color & 0xFF000000) >> 24;
		e->my_img[i + 1] = (e->color & 0x00FF0000) >> 16;
		e->my_img[i + 2] = (e->color & 0x0000FF00) >> 8;
		e->my_img[i + 3] = (e->color & 0x000000FF) >> 0;

	}
}