/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:07:20 by vrossi            #+#    #+#             */
/*   Updated: 2019/04/18 18:47:17 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	checkdebut(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static int	checkfin(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	i = i - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i)
		i--;
	return (i + 1);
}

char		*ft_strtrim(char const *s)
{
	size_t	len;
	char	*res;

	if (s)
	{
		if (checkdebut(s) == (int)ft_strlen(s))
		{
			res = (char *)malloc(sizeof(char));
			res[0] = '\0';
			return (res);
		}
		len = checkfin(s) - checkdebut(s);
		if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		res = ft_strsub(s, (unsigned int)checkdebut(s), len);
		return (res);
	}
	else
		return (NULL);
}
