/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:14:48 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/07 18:14:49 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

void		apply_termcap(int macro)
{
	char	*res;

	res = NULL;
	if (macro == SC)
		res = tgetstr("sc", glob->test);
	else if (macro == DL)
		res = tgetstr("dl", glob->test);
	else if (macro == RC)
		res = tgetstr("rc", glob->test);
	else if (macro == LE)
		res = tgetstr("le", glob->test);
	if (res != NULL)
		ft_putstr_fd(res, 2);
}
