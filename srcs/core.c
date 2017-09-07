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
//	char		command[1024];
	char		*command;
	int 		ret_size;
	int 		a;

	if (!(command = (char *)malloc(sizeof(char) * 1024)))
		exit(EXIT_SUCCESS);
	(void)env;
	a = 0;
	apply_termcap(SC);						// GET CURSOR POSITION
	ft_strclr(input);
	ft_memset(command, 0, 1024);
	ft_putstr(PROMPT);					// PRINT PROMPT
	while ((ret_size = read(0, input, 1024)) < 1024 && a < 1024)
	{
//		printf("[0] = %d | [1] = %d | [2] = %d\n", input[0], input[1], input[2]);
		if (input[0] == 10)
		{
			ft_debug("RETURN KEY PRESSED");
			ft_debug(command);
			if (ft_strncmp(command, "exit", 4) == 0)
			{
				free(command);
				free_d_char(env);
				while (1);
				exit(EXIT_SUCCESS);
			}
			ft_strclr(command);
			ft_strclr(input);
			core(env);
		}
		else if (input[0] == 27 && input[1] == 91 && input[2] == 68)
		{
			apply_termcap(DL);
			apply_termcap(RC);
			ft_putstr(PROMPT);
			ft_putstr(command);
			apply_termcap(LE);
			a -= 2;
		}
		else if (input[0] == 27 && input[1] == 91 && input[2] == 67)
			// RIGHT ARROW
		else if (input[0] == 27 && input[1] == 91 && input[2] == 65)
			// UP ARROW
		else if (input[0] == 27 && input[1] == 91 && input[2] == 66)
			// DOWN ARROW
		else if (input[0] == 127)
		{
			apply_termcap(DL);
			apply_termcap(RC);
			if (a > 0)
			{
				command[a - 1] = 0;
				a -= 2;
			}
			ft_putstr(PROMPT);
			ft_putstr(command);
			ft_strclr(input);
		}
		else
		{
			if (command[a] == 0)
				command[a] = input[ret_size - 1];
			else
			{
				command = shift_right(command, a, input[ret_size - 1]);
				ft_debug("command[a] not empty");
				ft_debug(command);
			}
			ft_putchar(command[a]);
		}
		a++;
	}
	if (ret_size >= 1024 || a >= 1024)
		ft_debug("Error : The command you wrote is too long.");
}

char		*shift_right(char *command, int pos, char c)
{
	int		a;

	a = 0;
	while (command[a])
		a++;
	while (a > pos)
	{
		command[a + 1] = command[a];
		a--;
	}
	command[a] = c;
	return (command);
}
