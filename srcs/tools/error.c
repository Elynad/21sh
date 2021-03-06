/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:03:53 by hublanc           #+#    #+#             */
/*   Updated: 2017/09/13 19:44:44 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		print_error(int err, char *cmd)
{
	if (err == 1)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	if (err == 2)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(cmd, 2);
	}
	if (err == 3)
		ft_putstr_fd("cd: HOME not set\n", 2);
	if (err == 4)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	if (err == 5)
		ft_putstr_fd("Invalid argument\n", 2);
}

void		print_usage(char c)
{
	ft_putstr_fd("illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: env [-i] [-u name] [name=value ...]", 2);
	ft_putstr_fd(" [utility[argument ...]]\n", 2);
}

int			check_access(char *path, char **env)
{
	int		res;

	(void)env;
	res = 1;
	if (access(path, F_OK) == -1)
		res = -1;
	if (res != -1 && access(path, X_OK) == -1)
		res = -2;
	return (res);
}

int			pwdnotset(char ***env)
{
	char		**new;
	int			pos;

	new = prep_setenv("PWD", NULL);
	ft_setenv(new, env);
	del_tabstr(&new);
	pos = in_env("PWD", *env);
	return (pos);
}

void		get_signal(int n)
{
	if (g_is_child)
		return ;
	if (n == SIGINT)
	{
		ft_putchar('\n');
		print_prompt();
	}
	else if (n == SIGSEGV)
		ft_putstr_fd(" Segmentation fault: 11\n", 2);
	else if (n == SIGABRT)
		ft_putstr_fd(" Abort trap: 6\n", 2);
	else if (n == SIGBUS)
		ft_putstr_fd(" Bus error: 10\n", 2);
}

void		event_not_found(char *str)		// May need to be in print_error
{
	int		i;

	i = 0;
	ft_putstr("shell: event not found: ");
	while (str[i] && str[i] != ' ')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}