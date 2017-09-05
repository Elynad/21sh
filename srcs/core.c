/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 08:46:11 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/04 08:46:13 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

void		core(t_control *env, t_global *glob)
{
	char		str[1024];
	t_control	*tokens;

	tokens = NULL;
	ft_strclr(str);
	ft_putstr("mameyer's 21sh $> ");				// SET PROMPT
	while (read(0, &str, 1024))
	{
		str[ft_strlen(str) - 1] = '\0';
		if (ft_strlen(str) > 0 && check_str(str) != -1)
		{
			if (ft_strcmp(str, "exit") == 0)
			{
				dll_clear_list(env);
				if (tokens)
					dll_clear_list(tokens);
//				if (tcsetattr(0, TCSANOW, &glob->default_term) == -1)
//					exit(EXIT_FAILURE);
				exit(EXIT_SUCCESS);
			}
			ft_putstr("INPUT = ");
			ft_putendl(str);
			tokens = lexer(str);
			ft_putchar('\n');
			print_list(tokens);
		}
		ft_strclr(str);
		core(env, glob);

	}
}