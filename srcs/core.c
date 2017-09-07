/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:48:36 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/07 13:48:37 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

void		core(char **env)
{
	char		input[1024];
	char		command[1024];
	char		*res;
	char		*cursor;
	int 		ret_size;
	int 		a;

	(void)env;
	a = 0;
	cursor = tgetstr("sc", glob->test);		// GET CURSOR POSITION
	ft_putstr_fd(cursor, 2);
	ft_strclr(input);
	ft_strclr(command);
	ft_putstr(PROMPT);					// PRINT PROMPT
	while ((ret_size = read(0, input, 1024)) < 1024)
	{
//		printf("[0] = %d | [1] = %d | [2] = %d\n", input[0], input[1], input[2]);
		if (input[0] == 10)
		{
			ft_debug("RETURN KEY PRESSED");
			ft_debug(command);
			if (ft_strncmp(command, "exit", 4) == 0)
			{
				free_d_char(env);
				while (1);
				exit(EXIT_SUCCESS);
			}
			ft_strclr(command);
			ft_strclr(input);
			core(env);
		}
		else if (input[0] == 127)
		{
			res = tgetstr("dl", glob->test);
			ft_putstr_fd(res, 2);
			res = tgetstr("rc", glob->test);
			ft_putstr_fd(res, 2);
			if (a > 0)
			{
				command[a - 1] = 0;
				a -= 2;
			}
	//		ft_putchar('\n');
			ft_putstr(PROMPT);
			ft_putstr(command);
			ft_strclr(input);
		}
		else
		{
			command[a] = input[ret_size - 1];
			ft_putchar(command[a]);
		}
		a++;
	}
	if (ret_size >= 1024)
		ft_debug("Error : The command you wrote is too long.");
}
