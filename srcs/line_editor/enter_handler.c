/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:30:26 by hublanc           #+#    #+#             */
/*   Updated: 2017/09/14 14:13:05 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		enter_handler(t_cmd *cmd, t_control **history, char ***env)
{
	char	c;

	ft_putchar('\n');
	if (!cmd->str)
		return (choose_prompt(cmd));
	c = check_quote(cmd->str);
	if (c == '\'' || c == '"')
		prompt_quote(cmd, history, c, 0);
	else if (c == '\\')
		prompt_backslash(cmd, history, 0);
	if (cmd->str && cmd->str[0] != '!')
		(*history) = dll_add_new_elem_frnt(*history, cmd->str);
	routine(cmd->str, env, history);
	clear_cmd(cmd);
	*cmd = init_cmd(return_prompt());
}

void		enter_handler_quote(t_cmd *cmd, t_control **history)
{
	char		c;

	cmd->str_quote = ft_strapp(cmd->str_quote, cmd->str);
	ft_strdel(&(cmd->str));
	ft_putchar('\n');
	c = check_quote(cmd->str_quote);
	if (!c)
		return ;
	else if ((c == '"' && !ft_strcmp("dquote> ", cmd->prompt))
	|| (c == '\'' && !ft_strcmp("quote> ", cmd->prompt)))
	{
		ft_putstr(cmd->prompt);
		cmd->col = cmd->prlen + 1;
		cmd->str_quote = ft_strapp(cmd->str_quote, "\n");
	}
	else if ((c == '"' && !ft_strcmp("quote> ", cmd->prompt))
	|| (c == '\'' && !ft_strcmp("dquote> ", cmd->prompt)))
		prompt_quote(cmd, history, c, 1);
	else if (c == '\\')
		prompt_backslash(cmd, history, 1);
}

void		enter_handler_backslash(t_cmd *cmd, t_control **history)
{
	char		c;

	cmd->str_quote = ft_strapp(cmd->str_quote, cmd->str);
	ft_strdel(&(cmd->str));
	ft_putchar('\n');
	c = check_quote(cmd->str_quote);
	if (!c)
		cmd->end_bs = 1;
	else if (c == '\\')
	{
		ft_putstr(cmd->prompt);
		cmd->col = cmd->prlen + 1;
		cmd->str_quote = ft_strdelone(cmd->str_quote,
		(int)ft_strlen(cmd->str_quote));
	}
	else if (c == '\'' || c == '"')
	{
		cmd->end_bs = 1;
		prompt_quote(cmd, history, c, 1);
	}
}

void		enter_handler_heredoc(t_cmd *cmd)
{
	ft_putchar('\n');
	if (cmd->str && !ft_strcmp(cmd->str, cmd->eof))
	{
		ft_strdel(&(cmd->str));
		cmd->end_eof = 1;
		return ;
	}
	cmd->str_quote = ft_strapp(cmd->str_quote, cmd->str);
	ft_putstr(cmd->prompt);
	cmd->col = cmd->prlen + 1;
	cmd->str_quote = ft_str_chr_cat(cmd->str_quote, '\n');
	ft_strdel(&(cmd->str));
}

void		enter_hub(t_cmd *cmd, t_control **history, char ***env)
{
	if (!ft_strcmp(cmd->prompt, "dquote> ")
	|| !ft_strcmp(cmd->prompt, "quote> "))
		enter_handler_quote(cmd, history);
	else if (!ft_strcmp(cmd->prompt, "> "))
		enter_handler_backslash(cmd, history);
	/*
	else if (!ft_strcmp(cmd->prompt, "pipe> "))
		enter_handler_pipe(cmd, history, env);*/
	else if (!ft_strcmp(cmd->prompt, "heredoc> "))
		enter_handler_heredoc(cmd);
	else
		enter_handler(cmd, history, env);
}
