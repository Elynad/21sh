/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:40:51 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/11 15:54:56 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (*s)
		s++;
	while (*s != (char)c && i > 0)
	{
		s--;
		i--;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
