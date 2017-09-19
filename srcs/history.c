/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 07:41:18 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/16 20:02:33 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

void		history_search(t_control *history, char *command)
{
	char	input[3];
	int		index;
	int		a;
	char	*search;
	t_lst	*tmp;

	a = 0;
	index = 0;
	tmp = NULL;
	if (!(search = (char *)malloc(sizeof(char) * 1024)))
		exit(EXIT_FAILURE);
	ft_memset(search, 0, 1024);
	apply_termcap(DL);
	apply_termcap(RC);
	ft_putstr(PROMPT);
	ft_putstr(command);
	ft_putstr("\nbck-i-search: _");
	while (read(0, input, 3))
	{
		if (history && history->length > 0)
			tmp = history->end;
		if (input[0] == 27 && input[1] == 91
			&& (input[2] == 68 || input[2] == 67))
			move_cursor_sides(input[2], &index, a, (int)ft_strlen(search));
		else if (input[0] == 127)
			search = delete_key(search, &a, index);
		else
			search = add_char(search, input[0], index, &a);
		while (tmp != NULL)
		{
			if (ft_strstr(tmp->name, search) != NULL)
			{
				apply_termcap(DL);
				apply_termcap(RC);
				ft_putstr(PROMPT);
				ft_putstr(tmp->name);
				ft_putstr("\nbck-i-search: _");
				ft_putstr(search);
				break ;
			}
			tmp = tmp->prev;
		}
		if (!tmp)
		{
			apply_termcap(DL);
			apply_termcap(RC);
			ft_putstr(PROMPT);
			ft_putstr("\nfailing bck-i-search: ");
			ft_putstr(search);
		}
	}
	(void)history;
}

char		*down_history(int *previous, t_control *history, int *a)
{
	t_lst		*tmp;
	int			test;

	test = 2;
	tmp = NULL;
	if (history == NULL || history->length == 0)
		return ("");
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
		*a = ft_strlen(tmp->name);
		return (tmp->name);
	}
	else
		return (NULL);
}

char		*up_history(int *previous, t_control *history, int *a)
{
	t_lst		*tmp;
	int			test;

	tmp = NULL;
	test = 2;
	if (history == NULL || history->length == 0)
		return ("");
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
		*a = ft_strlen(tmp->name);
		return (tmp->name);
	}
	else
		return (NULL);
}

void		add_history(t_control *history, char *command, char **env)
{
	if (command && ft_strlen(command) > 0)
		history = dll_add_new_elem_end(history, command);
//	ft_putstr("\nCOMMAND VALUE = ");
//	ft_debug(command);
	ft_putchar('\n');	// DEBUG TEST
	/*
	** TEST : GO IN HISTORY FUNC
	*/
	if (ft_strncmp(command, "history", 7))
		history_builtin(command, history);
	else
		splitter(env, history, command);
}

void		history_builtin(char *command, t_control *history)
{
	(void)history;
	if (ft_strcmp(command, "history") != 0)
	{

	}
	if (ft_strstr(command, "-c"))
	{
		// CLEAR HISTORY
	}
	if (1)
	{
	}
}
