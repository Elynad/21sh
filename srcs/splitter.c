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
	int		a;

	a = 0;
	split = str_split(command, ';', 1);

	ft_print_tab(split, '\n');		// DEBUG
	while (split[a])
	{
		lexer(env, split[a]);
		a++;
	}

	a = 0;
	// FREE SPLIT CREATE LEAKS - WTF ?
/*	while (split[a])
	{
		free(split[a]);
		split[a] = NULL;
	}
	free(split);
	split = NULL;*/
	parsing(env, history);
}
