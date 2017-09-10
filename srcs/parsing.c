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
	int			index;

	ft_memset(input, 0, 3);
	command = init_command(&a, &index, &previous);
	while (read(0, input, 3))
	{
		if (input[0] == 10)
			add_history(history, command, env);
		else if (input[0] == 27 && input[1] == 91
			&& (input[2] == 68 || input[2] == 67))
			move_cursor_sides(input[2], &index, a, (int)ft_strlen(command));
		else if (input[0] == 27 && input[1] == 91 && input[2] == 66)
			command = ft_strcpy(command, down_history(&previous, history));
		else if (input[0] == 27 && input[1] == 91 && input[2] == 65)
			command = ft_strcpy(command, up_history(&previous, history));
		else if (input[0] == 127)
			command = delete_key(command, &a, index);
		else
			command = add_char(command, input[0], index, &a);
		ft_memset(input, 0, 3);
	}
}

char		*init_command(int *a, int *index, int *previous)
{
	char		*command;

	apply_termcap(SC);
	ft_putstr(PROMPT);
	*a = 0;
	*index = 0;
	*previous = 0;
	if (!(command = (char *)malloc(sizeof(char) * 1024)))
		exit(EXIT_FAILURE);
	ft_memset(command, 0, 1024);
	return (command);
}

char		*add_char(char *str, char c, int index, int *a)
{
	int		test;

	test = 0;
	if (str[*a] == 0 && index == 0)
	{
		str[*a] = c;
		ft_putchar(str[*a]);
	}
	else
	{
		str = shift_right_string(str, (int)ft_strlen(str) - index, c);
		apply_termcap(DL);
		apply_termcap(RC);
		ft_putstr(PROMPT);
		ft_putstr(str);
		while (test < index)
		{
			apply_termcap(LE);
			test++;
		}
	}
	(*a)++;
	return (str);
}

char		*delete_key(char *str, int *a, int cursor)
{
	int		test;
	int		index;

	index = ft_strlen(str) - 1 - cursor;
	test = 0;
	while (str[index + 1] && index + 1 > 0)
	{
		str[index] = str[index + 1];
		index++;
	}
	str[index] = '\0';
	if (*a > 0)
		(*a)--;
	apply_termcap(DL);
	apply_termcap(RC);
	ft_putstr(PROMPT);
	ft_putstr(str);
	while (test < cursor)
	{
		apply_termcap(LE);
		test++;
	}
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
