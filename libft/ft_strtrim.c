/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:25:12 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/14 18:12:32 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		a;
	int		b;
	int		c;
	char	*str;

	a = 0;
	c = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (s[a] != '\0')
		a++;
	b = a;
	a--;
	while ((s[a] == ' ' || s[a] == '\n' || s[a] == '\t') && a >= 0)
	{
		c++;
		a--;
	}
	str = (char *)malloc(sizeof(char) * (b - c) + 1);
	if (!str)
		return (NULL);
	str[b - c] = '\0';
	return (ft_strncpy(str, s, (b - c)));
}
