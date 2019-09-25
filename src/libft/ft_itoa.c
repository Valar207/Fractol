/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:11:26 by vrossi            #+#    #+#             */
/*   Updated: 2019/04/18 19:42:13 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		intlen(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = intlen(n);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n == 0)
		res[0] = '0';
	res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n)
	{
		len--;
		res[len] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}
