/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 23:29:28 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/05 23:29:34 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

void		launch_commands(t_control *tokens, t_control *env)
{
	t_lst		*tmp;

	tmp = tokens->begin;
	while (tmp != NULL)
	{
		check_commands(tmp, env);
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		tokens = dll_clear_list(tokens);
		core(env);
	}
}

void		check_commands(t_lst *token, t_control *env)
{
	
}