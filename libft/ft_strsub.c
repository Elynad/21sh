/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:26:18 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/15 15:55:32 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s)
	{
		i = 0;
		str = ft_strnew(len);
		if (!(str))
			return (NULL);
		while (i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		while (str[i])
		{
			str[i] = '\0';
			i++;
		}
		return (str);
	}
	return (NULL);
}
