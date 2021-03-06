/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:37:30 by hublanc           #+#    #+#             */
/*   Updated: 2017/09/13 19:40:01 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

char		**init_env(void)
{
	char		**new;
	char		*pwd;
	char		*tmp;

	new = (char**)ft_memalloc(sizeof(char*) * 4);
	pwd = ft_strdup("PWD=");
	tmp = getcwd(NULL, PATH_MAX + 1);
	pwd = ft_strapp(pwd, tmp);
	new[0] = ft_strdup(pwd);
	new[1] = ft_strdup("SHLVL=1");
	new[2] = ft_strdup("_=/usr/bin/env");
	new[3] = NULL;
	ft_strdel(&tmp);
	ft_strdel(&pwd);
	return (new);
}

int			main(int ac, char **av, char **env)
{
	t_cmd		cmd;
	t_control	*history;
	char		**cp_env;
	int			status;

	(void)ac;
	(void)av;
	cp_env = (*env) ? get_env(env, 1) : init_env();
	signal(SIGINT, get_signal);
	set_terminal();

	 /*
	 *test
	 
	t_token		*list;
	char		*str;
	char		*str1;
	str = ft_strdup("ls -a ; ls | cat | wc -c > toto < winz");
	str1 = ft_strdup("cd bin ; echo test ; ls | cat > blablou");
	//char *test = ft_strdup("mkdir test ; cd test ; ls -a ; ls | cat | wc -c > fifi ; cat fifi");
	char *str2= ft_strdup("ls");
	//char *strt = ft_strdup("ls | cat >< 1");
	list = tokenizer(str2);
	display_token(list);	
	ft_putcolor("\nSORT\n");
	list = sort_token(list);
	display_token(list);
	ft_putcolor("\nPRINT_TREE\n\n");
	t_node	*tree;
	tree = create_tree(list);
	ft_putstr("\n\n");
	node_print(tree, 0, 6);
	exec_tree(tree, &cp_env);
	ft_putcolor("FIN TEST");
	ft_putchar('\n');
	
	//FIN TEST*/

	status = 0;
	print_prompt();
	cmd = init_cmd(return_prompt());
	history = NULL;
	history = load_history();
	while (1)
		key_handler(&cmd, &history, &cp_env);
	del_tabstr(&cp_env);
}
