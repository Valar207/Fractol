/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:13:14 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/16 10:55:51 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *str, size_t n)
{
	char	*dst;

	if (!(dst = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_strncpy(dst, str, n);
	dst[n] = '\0';
	return (dst);
}
