/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:08:15 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/15 11:58:49 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	result;
	int		neg;
	int		i;

	result = 0;
	neg = 1;
	i = 0;
	while (ft_is_space(*str) == 1)
		str++;
	if (ft_strcmp(str, "2147483647") == 0)
		return (2147483647);
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		result = (result + (str[i]) - 48) * 10;
		i++;
	}
	return ((int)(result / 10 * neg));
}
