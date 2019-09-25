/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:04:56 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/10 13:08:00 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_read(int fd, char *str)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ret == -1)
		{
			free(str);
			return (NULL);
		}
		buf[ret] = '\0';
		tmp = str;
		str = ft_strjoin(str, buf);
		ft_memdel((void **)&tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (str);
}

static void			ft_saveline(char **save, char **line)
{
	size_t			size;
	char			*tmp;

	tmp = NULL;
	size = 0;
	while ((*save)[size] != '\n' && (*save)[size] != '\0')
		size++;
	if ((*save)[size] == '\n')
	{
		*line = ft_strsub(*save, 0, size);
		tmp = *save;
		*save = ft_strsub(*save, size + 1, ft_strlen(*save) - ft_strlen(*line));
		ft_memdel((void **)&tmp);
	}
	else if ((*save)[size] == '\0')
	{
		*line = ft_strdup(*save);
		ft_memdel((void **)save);
	}
}

int					get_next_line(const int fd, char **line)
{
	static char		*save[FD_MAX];

	if ((fd < 0) || (line == NULL) || (read(fd, 0, 0) < 0))
		return (-1);
	if (!save[fd])
		save[fd] = ft_strnew(0);
	save[fd] = ft_read(fd, save[fd]);
	ft_saveline(&save[fd], line);
	if (!save[fd] && *line[0] == '\0')
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	return (1);
}
