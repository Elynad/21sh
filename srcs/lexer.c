/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 05:00:29 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/10 05:00:31 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

/*
**	The lexer func sets command into tokens
*/

void		lexer(char **env, char *command)
{
	t_control	*tokens;
	int			a;

	tokens = NULL;
	(void)env;
	a = 0;
	tokens = add_token(tokens, command, &a);
	dll_print_list(tokens, '\n');				// DEBUG
	ft_debug(" ");
	token_tree(tokens, env);
}

t_control		*set_redirection_token_1(t_control *tokens, char *str, int *a)
{
	if (str[*a] && str[*a] == '|')
	{
		tokens = dll_add_new_elem_end(tokens, "|");
		tokens->end->type = PIPE;
		(*a)++;
	}
	else if (str[*a] && str[*a] == '>' && str[*a + 1] && str[*a + 1] == '>')
	{
		dll_add_new_elem_end(tokens, ">>");
		tokens->end->type = REDIRECTION;
		(*a) += 2;
	}
	else if (str[*a] && str[*a] == '>')
	{
		tokens = dll_add_new_elem_end(tokens, ">");
		tokens->end->type = REDIRECTION;
		(*a)++;
	}
	else
		tokens = set_redirection_token_2(tokens, str, a);
	return (tokens);
}

t_control		*set_redirection_token_2(t_control *tokens, char *str, int *a)
{
	if (str[*a] && str[*a] == '<' && str[*a + 1] && str[*a + 1] == '<')
	{
		tokens = dll_add_new_elem_end(tokens, "<<");
		tokens->end->type = REDIRECTION;
		(*a) += 2;
	}
	else if (str[*a] && str[*a] == '<')
	{
		tokens = dll_add_new_elem_end(tokens, "<");
		tokens->end->type = REDIRECTION;
		(*a)++;
	}
	else
		tokens = set_and_token(tokens, str, a);
	return (tokens);
}

t_control		*set_and_token(t_control *tokens, char *str, int *a)
{
	if (str[*a] && str[*a] == '&' && str[*a + 1] && str[*a + 1] == '&')
	{
		tokens = dll_add_new_elem_end(tokens, "&&");
		tokens->end->type = AND;
		(*a) += 2;
	}
	else if (str[*a] && str[*a] == '&')
	{
		tokens = dll_add_new_elem_end(tokens, "&");
		tokens->end->type = AND;
		(*a)++;
	}
	else
		tokens = set_command_token(tokens, str, a);
	return (tokens);
}

t_control		*set_command_token(t_control *tokens, char *str, int *a)
{
	int		save;
	char	*tmp;

	save = *a;
	while (str[save] && str[save] != '<' && str[save] != '>'
		&& str[save] != '|' && str[save] != '&')
		save++;
	if (!(tmp = (char *)malloc(sizeof(char) * (save - *a + 1))))
		exit(EXIT_FAILURE);
	save = 0;
	while (str[*a] && str[*a] != '<' && str[*a] != '>'
		&& str[*a] != '|' && str[*a] != '&')
	{
		tmp[save] = str[*a];
		save++;
		(*a)++;
	}
	tmp[save] = '\0';
	tokens = dll_add_new_elem_end(tokens, tmp);
	tokens->end->type = COMMAND;
	free(tmp);
	tmp = NULL;
	return (tokens);
}

t_control		*add_token(t_control *tokens, char *str, int *a)
{
	while (str[*a])
		tokens = set_redirection_token_1(tokens, str, a);
	return (tokens);
}
