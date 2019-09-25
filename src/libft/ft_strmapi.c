/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:02:03 by vrossi            #+#    #+#             */
/*   Updated: 2019/04/18 18:46:10 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t			i;
	unsigned int	j;
	char			*str;

	if (s != NULL)
	{
		if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		i = 0;
		j = 0;
		while (i < ft_strlen(s))
		{
			str[i] = f(j, s[i]);
			i++;
			j++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
