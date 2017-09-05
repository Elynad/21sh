/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:42:54 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/11 15:44:46 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*cpy1;
	unsigned char		*cpy2;

	cpy1 = (unsigned char *)s1;
	cpy2 = (unsigned char *)s2;
	while (n > 0 && *cpy1 == *cpy2)
	{
		cpy1++;
		cpy2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*cpy1 - *cpy2);
}
