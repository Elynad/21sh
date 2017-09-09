/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 21:01:32 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/23 15:21:09 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_test(char **line, char *str)
{
	char	*tmp;

	if (ft_strchr(str, '\n'))
	{
		*ft_strchr(str, '\n') = '\0';
		*line = str;
		tmp = ft_strdup(&str[ft_strlen(str) + 1]);
		return (tmp);
	}
	if (ft_strlen(str))
	{
		*line = str;
		str = ft_strdup(&str[ft_strlen(str)]);
		return (str);
	}
	return (NULL);
}

int					get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*str[OPEN_MAX];
	int			rd;
	char		*tmp;

	if (fd < 0 || fd >= OPEN_MAX)
		return (-1);
	if (!(str[fd]))
	{
		if (!(str[fd] = ft_strnew(BUFF_SIZE)))
			return (-1);
	}
	while ((rd = read(fd, buff, BUFF_SIZE)))
	{
		if (rd == -1)
			return (rd);
		buff[rd] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(str[fd], '\n') != NULL)
			break ;
	}
	return ((str[fd] = ft_test(line, str[fd])) ? 1 : 0);
}
