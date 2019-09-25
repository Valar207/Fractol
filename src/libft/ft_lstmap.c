/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:23:15 by vrossi            #+#    #+#             */
/*   Updated: 2019/04/18 19:42:42 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*res;
	t_list	*tmp;

	if (lst && f)
	{
		new = f(lst);
		res = new;
		tmp = lst->next;
		while (tmp)
		{
			new->next = f(tmp);
			tmp = tmp->next;
			new = new->next;
		}
		return (res);
	}
	return (NULL);
}
