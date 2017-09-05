/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:57:08 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/15 16:46:25 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		len;
	int		i;

	if (s && f)
	{
		len = ft_strlen(s);
		i = 0;
		str = ft_strnew(len);
		if (!str)
			return (NULL);
		while (*s)
		{
			str[i] = f(i, *s);
			i++;
			s++;
		}
	}
	if (!s || !f)
		str = NULL;
	return (str);
}
