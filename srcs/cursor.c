/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 07:41:09 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/10 07:41:11 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

void		move_cursor_sides(char input, int *index, int a, int len)
{
	if (input == 68)
	{
		if (*index < a && *index < len)
		{
			apply_termcap(LE);
			(*index)++;
		}
	}
	else if (input == 67)
	{
		if (*index <= a && *index > 0)
		{
			apply_termcap(ND);
			(*index)--;
		}
	}
}
