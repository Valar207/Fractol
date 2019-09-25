/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:39:57 by vrossi            #+#    #+#             */
/*   Updated: 2019/04/11 10:51:51 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	char		*s1;
	char		*s2;

	i = 0;
	s1 = (char *)haystack;
	s2 = (char *)needle;
	if (!s2[0])
		return (s1);
	while (s1[i] && i < len)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s2[j] && s2[j] == s1[j + i] && j + i < len)
				j++;
			if (s2[j] == '\0')
				return (s1 + i);
		}
		i++;
	}
	return (NULL);
}
