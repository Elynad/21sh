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

void			core(t_control *env)
{
	char		str[1024];
	t_control	*tokens;
	int			size;

	if (!(tokens = malloc(sizeof(t_control))))
		exit(EXIT_FAILURE);
	tokens = NULL;
	ft_strclr(str);
	ft_putstr("mameyer's 21sh $> ");				// SET PROMPT
	while ((size = read(0, &str, 1024)))
	{
		str[size - 1] = '\0';				// DELETE FINAL \n
		ft_debug("INPUT");
		ft_debug(str);
		if (ft_strlen(str) > 0 && check_str(str) != -1)
		{
			tokens = lexer(str, tokens);
			ft_debug("TOKEN VALUE");\
			print_list(tokens);
			if (ft_strcmp(str, "exit") == 0)
			{
				dll_clear_list(env);
				if (tokens)
					tokens = dll_clear_list(tokens);
				exit(EXIT_SUCCESS);
			}
		}
		ft_strclr(str);
		core(env);
	}
}
