/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:48:36 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/07 13:48:37 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

void		parsing(char **env, t_control *history)
{
	char		input[3];
	char		*command;
	int			a;
	int			previous;
	int			test;
	int			index;
	int			cursor_pos;
	t_lst		*tmp;

	(void)env;
	ft_memset(input, 0, 3);
	apply_termcap(SC);
	ft_putstr(PROMPT);
	a = 0;
	index = 0;
	cursor_pos = 0;
	previous = 0;
	if (!(command = (char *)malloc(sizeof(char) * 1024)))
		exit(EXIT_FAILURE);
	ft_memset(command, 0, 1024);
	while (read(0, input, 3))
	{
		if (input[0] == 10)		// RETURN
		{
			if (command && ft_strlen(command) > 0)
			{
				history = dll_add_new_elem_end(history, command);
				tmp = history->end;
			}
			ft_putstr("\nCOMMAND VALUE = ");
			ft_debug(command);
			parsing(env, history);
		}
		else if (input[0] == 27 && input[1] == 91 && input[2] == 68)	// LEFT
		{
			if (index < a && index < (int)ft_strlen(command))
			{
				apply_termcap(LE);
				index++;
			}
		}
		else if (input[0] == 27 && input[1] == 91 && input[2] == 67)	// RIGHT
		{
			if (index <= a && index > 0)
			{
				apply_termcap(ND);
				index--;
			}
		}
		else if (input[0] == 27 && input[1] == 91 && input[2] == 66)	// DOWN
		{
			if (previous > 2)
				previous--;
			tmp = history->end;
			int 	test3 = 2;
			while (test3 < previous && tmp != NULL && tmp->prev != NULL)
			{
				tmp = tmp->prev;
				test3++;
			}
			if (tmp != NULL && tmp->name && ft_strlen(tmp->name) > 0)
			{
				apply_termcap(DL);
				apply_termcap(RC);
				ft_putstr(PROMPT);
				ft_putstr(tmp->name);
			}
			if (tmp->prev)
				tmp = tmp->prev;
		}
		else if (input[0] == 27 && input[1] == 91 && input[2] == 65)	// UP
		{
			if (previous <= history->length)
				previous++;
			tmp = history->end;
			int		test2 = 2;
			while (test2 < previous && tmp != NULL && tmp->prev != NULL)
			{
				tmp = tmp->prev;
				test2++;
			}
			if (tmp != NULL && tmp->name && ft_strlen(tmp->name) > 0)
			{
				apply_termcap(DL);
				apply_termcap(RC);
				ft_putstr(PROMPT);
				ft_putstr(tmp->name);
			}
			if (tmp->prev)
				tmp = tmp->prev;
		}
		else if (input[0] == 127)										// DELETE
		{
			command = shift_left_string(command, (ft_strlen(command) - 1 - index));
			if (a > 0)
				a--;
			apply_termcap(DL);
			apply_termcap(RC);
			ft_putstr(PROMPT);
			ft_putstr(command);
			test = 0;
			while (test < index)
			{
				apply_termcap(LE);
				test++;
			}
		}
		else
		{
			if (command[a] == 0 && index == 0)
			{
				command[a] = input[0];
				ft_putchar(command[a]);
			}
			else
			{
				command = shift_right_string(command, (int)ft_strlen(command) - index, input[0]);
				apply_termcap(DL);
				apply_termcap(RC);
				ft_putstr(PROMPT);
				ft_putstr(command);
				test = 0;
				while (test < index)
				{
					apply_termcap(LE);
					test++;
				}
			}
			a++;
			cursor_pos++;
		}
		ft_memset(input, 0, 3);
	}
}

char		*shift_left_string(char *str, int index)
{
	while (str[index + 1] && index + 1 > 0)
	{
		str[index] = str[index + 1];
		index++;
	}
	str[index] = '\0';
	return (str);
}

char		*shift_right_string(char *str, int index, char c)
{
	int			a;
	int			b;
	char		*tmp;

	a = 0;
	b = 0;
	tmp = ft_strdup(str);
	while (a != index)
		a++;
	b = a;
	str[b] = c;
	b++;
	while (tmp[a])
	{
		str[b] = tmp[a];
		a++;
		b++;
	}
	free(tmp);
	return (str);
}
