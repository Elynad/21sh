/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_chr_cat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 19:05:52 by hublanc           #+#    #+#             */
/*   Updated: 2017/01/06 20:11:44 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_chr_cat(char *str, char c)
{
	int		i;

	i = 0;
	str = ft_realloc(str, 1);
	while (str[i] != '\0')
		i++;
	str[i] = c;
	return (str);
}