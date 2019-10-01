/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:18:17 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/18 11:40:46 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/keyboard_code.h"

void    color(t_env *e)
{
	if (e->sw == 1)
	{
   		if (e->chgcol == 2)
			e->color = 0x00080000; 
		else if (e->chgcol == 3)
			e->color = 0x00000800;
		else
		{
			e->color = 0x08000000;
			e->chgcol = 1;
		}
	}
	if (e->sw == 2)
		e->color = 0x25252500 * e->i >> 2;
    if (e->i == e->maxIterations)
	    e->color = 0x00000000;
}