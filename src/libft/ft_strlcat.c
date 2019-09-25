/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:44:24 by vrossi            #+#    #+#             */
/*   Updated: 2019/04/17 19:04:29 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	res;
	size_t	i;
	size_t	j;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	i = 0;
	j = 0;
	while (dst[j])
		j++;
	if (size <= ldst)
		return (size + lsrc);
	else
	{
		while (src[i] && i < size - ldst - 1)
			dst[j++] = src[i++];
		res = lsrc + ldst;
		dst[j] = '\0';
	}
	return (res);
}
