/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 04:52:57 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/04 04:52:58 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

int		main(int argc, char **argv, char **environment)
{
	t_control		*env;
	t_global		*glob;

	(void)argc;
	(void)argv;
	if (!environment)
		empty_env();
	if (!(env = malloc(sizeof(t_control))))
		exit(EXIT_FAILURE);
	if (!(glob = malloc(sizeof(t_global))))
		exit(EXIT_FAILURE);
//	init(glob);
	env = get_env(env, environment);
	core(env, glob);
	return (0);
}
