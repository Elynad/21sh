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

void		splitter(char **env, t_control *history, char *command)
{
	char		**commands;

	(void)env;
	(void)history;
	commands = split_entry(command);
	ft_debug("END OF LEXER");
//	ft_print_tab(commands, '\n');
	parsing(env, history);
}

char		**split_entry(char *str)
{
	char		**result;
	int			size;
	int			i;
	int			index;

	result = NULL;
	i = 0;
	index = 0;
	size = get_size(str);
	ft_debug("SIZE VALUE");
	ft_putnbr(size);
	if (!(result = (char **)malloc(sizeof(char *) * (size + 1))))
		exit(EXIT_FAILURE);
	while (i < size)
	{
		result[i] = set_command(str, &index);
		i++;
	}
	result[i] = NULL;
	return (result);
}

char		*set_command(char *str, int *index)
{
	(void)str;
	(void)*index;
	return (NULL);
}

int			get_command_size(char *str, int *index)
{
	int		size;
	int		save;

	size = 0;

	ft_debug("IN GET_COMMAND_SIZE, SIZE VALUE");
	ft_putnbr(size);
	return (size);
}

int			get_size(char *str)		// NEED TO NORM
{
	int		i;
	int		size;

	size = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			i++;
		}
		else if (str[i] == '"')
		{
			i++;
			while (str[i] && str[i] != '"')
				i++;
			i++;
		}
		else if (str[i] && str[i] == ';')
		{
			i++;
			size++;
		}
		else
			i++;
	}
	return (size);
}