/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:56:07 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/15 11:59:52 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(long n)
{
	int		len;

	len = 2;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*ft_strfill(char *str, int len, long n)
{
	int		neg;

	neg = 1;
	if (n < 0)
		neg = -1;
	n *= neg;
	str[--len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (neg == -1)
		str[len] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*str;

	len = ft_size(n);
	neg = 1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	str = ft_strfill(str, len, n);
	return (str);
}
