/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:09:08 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/07 13:09:10 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

void		free_d_char(char **d_char)
{
	int		a;

	a = 0;
	while (d_char && d_char[a])
	{
		free(d_char[a]);
		d_char[a] = NULL;
		a++;
	}
	free(d_char);
	d_char = NULL;
}
