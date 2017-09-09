/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:31:10 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/11 15:44:59 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*cpy;
	unsigned char		*str;
	size_t				i;

	str = (unsigned char *)src;
	cpy = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		cpy[i] = str[i];
		i++;
	}
	return (cpy);
}
