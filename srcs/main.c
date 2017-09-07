/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:55:46 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/07 12:55:48 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

int		main(int argc, char **argv, char **env)
{
	char		**dup_env;

	(void)argc;
	(void)argv;
	dup_env = duplicate_environment(env);
	if (!(glob = malloc(sizeof(t_glob))))
		exit(EXIT_FAILURE);
	init();
	core(dup_env);
	free_d_char(dup_env);
    if (tcsetattr(0, TCSANOW, &glob->default_term) == -1)
	    exit(EXIT_FAILURE);
	while (1);		// LEAKS CHECK
	return (0);
}
