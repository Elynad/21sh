/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 05:15:54 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/04 05:15:56 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"


t_control		*get_env(t_control *env, char **environment)
{
	int 		a;

	env = NULL;
	a = 0;
	while (environment[a])
	{
		env = dll_add_new_elem_end(env, environment[a]);
		a++;
	}
	return (env);
}

void			init(t_global *glob)
{
	char		*term_name;

	if ((term_name = getenv("TERM")) == NULL)
	{
		ft_putstr_fd("TERM VAR UNSET\n", 2);
		empty_env();
	}
	if (tgetent(NULL, glob->term_name) == -1)
		exit(EXIT_FAILURE);
	if (tcgetattr(0, &glob->term) == -1)
		exit(EXIT_FAILURE);
	if (tcgetattr(0, &glob->default_term) == -1)
		exit(EXIT_FAILURE);
	glob->term.c_lflag &= ~(ICANON);
	glob->term.c_cc[VMIN] = 1;
	glob->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &glob->term) == -1)
		exit(EXIT_FAILURE);
}
