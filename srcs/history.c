/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 07:41:18 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/10 07:41:20 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

char		*down_history(int *previous, t_control *history)
{
	t_lst		*tmp;
	int			test;

	test = 2;
	tmp = NULL;
	if (*previous > 2)
		(*previous)--;
	tmp = history->end;
	while (test < *previous && tmp != NULL && tmp->prev != NULL)
	{
		tmp = tmp->prev;
		test++;
	}
	if (tmp != NULL && tmp->name && ft_strlen(tmp->name) > 0)
	{
		apply_termcap(DL);
		apply_termcap(RC);
		ft_putstr(PROMPT);
		ft_putstr(tmp->name);
		return (tmp->name);
	}
	else
		return (NULL);
}

char		*up_history(int *previous, t_control *history)
{
	t_lst		*tmp;
	int			test;

	tmp = NULL;
	test = 2;
	if (*previous <= history->length)
		(*previous)++;
	tmp = history->end;
	while (test < *previous && tmp != NULL && tmp->prev != NULL)
	{
		tmp = tmp->prev;
		test++;
	}
	if (tmp != NULL && tmp->name && ft_strlen(tmp->name) > 0)
	{
		apply_termcap(DL);
		apply_termcap(RC);
		ft_putstr(PROMPT);
		ft_putstr(tmp->name);
		return (tmp->name);
	}
	else
		return (NULL);
}

void		add_history(t_control *history, char *command, char **env)
{
	if (command && ft_strlen(command) > 0)
		history = dll_add_new_elem_end(history, command);
	ft_putstr("\nCOMMAND VALUE = ");
	ft_debug(command);
	parsing(env, history);
}
