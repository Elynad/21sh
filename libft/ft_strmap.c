/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:51:47 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/15 16:46:52 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		len;
	int		i;

	if (s && f)
	{
		len = ft_strlen(s);
		str = ft_strnew(len);
		i = 0;
		if (!str)
			return (NULL);
		while (*s)
		{
			str[i] = f(*s);
			i++;
			s++;
		}
	}
	if (!s || !f)
		str = NULL;
	return (str);
}
