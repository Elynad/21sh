/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 13:43:58 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/10 13:43:59 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

/*
**	The splitter func will split the command line by ';', without splitting
**	';' that are between single and double quotes.
*/

void		splitter(char **env, t_control *history, char *command)
{
	char	**split;

	split = str_split(command, ';', 0);	// 0 = DO NOT FREE COMMAND;
	ft_print_tab(split, '\n');

	parsing(env, history);
}
