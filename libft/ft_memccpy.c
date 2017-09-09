/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:03:29 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/11 15:44:22 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	while (n > 0)
	{
		if (*(char *)src == c)
		{
			*(char *)dst = c;
			return (dst + 1);
		}
		*(char *)dst = *(char *)src;
		dst++;
		src++;
		n--;
	}
	return (NULL);
}
