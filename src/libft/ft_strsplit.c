/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:08:27 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/16 16:16:21 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_word(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i]) && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	len;
	size_t	i;

	if (!(s))
		return (NULL);
	len = count_word(s, c);
	if (!(res = (char **)ft_memalloc(sizeof(char *) * (len + 1))))
		return (NULL);
	res[len] = 0;
	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		if (*s || (!*s && len))
			res[i++] = ft_strndup(s - len, len);
	}
	return (res);
}
