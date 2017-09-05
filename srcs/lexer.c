/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 18:59:15 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/05 18:59:17 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

t_control		*lexer(char *str)
{
	t_control		*tokens;
	int				a;
	int				b;
	char			buffer[1024];

	if (!(tokens = malloc(sizeof(t_control))))
		exit(EXIT_FAILURE);
	tokens = NULL;
	ft_strclr(buffer);
	a = 0;
	while (str[a] == ' ' || str[a] == '\t')
		a++;
	while (str[a])
	{
		b = 0;
		if (str[a] == '\'')
			tokens = get_until_next_sq(str, &a, tokens);
		else if (str[a] == '"')
			tokens = get_until_next_dq(str, &a, tokens);
		else if (str[a] == ';')
		{
			tokens = dll_add_new_elem_end(tokens, ";");
			a++;
		}
		else if (str[a] == '|')
		{
			tokens = dll_add_new_elem_end(tokens, "|");
			a++;
		}
		else
		{
			while (str[a] && str[a] == ' ')
				a++;
			while (str[a] && str[a] != '\'' && str[a] != '"'
				&& str[a] != ';' && str[a] != '|')
			{
				if (str[a] != ' ' || str[a] != '\t')
				{
					buffer[b] = str[a];
					b++;
				}
				a++;
			}
			buffer[b] = '\0';
			if (ft_strlen(buffer) > 0)
				tokens = dll_add_new_elem_end(tokens, buffer);
			ft_strclr(buffer);
		}
	}
	return (tokens);
}

t_control		*get_until_next_sq(char *str, int *a, t_control *tokens)
{
	char	*tmp;
	int		b;

	b = 1;
	while (str[*a + b] && str[*a + b] != '\'')
		b++;
	if (!(tmp = (char *)malloc(sizeof(char) * (b + 2))))
		exit(EXIT_FAILURE);
	b = 0;
	tmp[b] = str[*a];
	(*a)++;
	b++;
	while (str[*a] && str[*a] != '\'')
	{
		tmp[b] = str[*a];
		(*a)++;
		b++;
	}
	tmp[b] = str[*a];
	b++;
	(*a)++;
	tmp[b] = '\0';
	tokens = dll_add_new_elem_end(tokens, tmp);
	free(tmp);
	tmp = NULL;
	return (tokens);
}

t_control		*get_until_next_dq(char *str, int *a, t_control *tokens)
{
	char	*tmp;
	int		b;

	b = 1;
	while (str[*a + b] && str[*a + b] != '"')
		b++;
	if (!(tmp = (char *)malloc(sizeof(char) * (b + 2))))
		exit(EXIT_FAILURE);
	b = 0;
	tmp[b] = str[*a];
	(*a)++;
	b++;
	while (str[*a] && str[*a] != '"')
	{
		tmp[b] = str[*a];
		(*a)++;
		b++;
	}
	tmp[b] = str[*a];
	b++;
	(*a)++;
	tmp[b] = '\0';
	tokens = dll_add_new_elem_end(tokens, tmp);
	free(tmp);
	tmp = NULL;
	return (tokens);
}
