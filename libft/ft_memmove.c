/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:39:19 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/11 15:47:04 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(void) * len);
	if (tmp != NULL)
	{
		tmp = ft_memcpy(tmp, src, len);
		dst = ft_memcpy(dst, tmp, len);
	}
	free(tmp);
	return (dst);
}
