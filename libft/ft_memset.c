/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:19:54 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/11 15:47:14 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cpy;
	size_t			i;

	cpy = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		cpy[i] = (unsigned char)c;
		i++;
	}
	return (cpy);
}
