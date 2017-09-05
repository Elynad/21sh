/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:56:17 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/15 16:46:00 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
		str = ft_strnew(size);
		if (!(str))
			return (NULL);
		str = ft_strcpy(str, s1);
		str = ft_strcat(str, s2);
	}
	if (!s1 || !s2)
		str = NULL;
	return (str);
}
