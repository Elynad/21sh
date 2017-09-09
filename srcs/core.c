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
	char		input[3];
	char		*command;
	int			a;
	int			index;
	int			cursor_pos;

	(void)env;
	ft_memset(input, 0, 3);
	apply_termcap(SC);
	ft_putstr(PROMPT);
	a = 0;
	index = 0;
	cursor_pos = 0;
	if (!(command = (char *)malloc(sizeof(char) * 1024)))
		exit(EXIT_FAILURE);
	ft_memset(command, 0, 1024);
	while (read(0, input, 3))
	{
		if (input[0] == 10)		// RETURN
		{
			ft_putstr("\nCOMMAND VALUE = ");
			ft_debug(command);
			core(env);
		}
		else if (input[0] == 27 && input[1] == 91 && input[2] == 68)	// LEFT
		{
			if (index < a)
			{
				apply_termcap(LE);
				index++;
			}
		}
		else if (input[0] == 27 && input[1] == 91 && input[2] == 67)	// RIGHT
		{
			if (index <= a && index > 0)
			{
				apply_termcap(ND);
				index--;
			}
		}
		else
		{
			if (command[a] == 0 && index == 0)
				command[a] = input[0];
			else
			{
				//ft_debug("COMMAND[A] NOT EMPTY - INDEX VALUE");
				//ft_putnbr(index);
				/*
				** index will be equal to the number of chars after the cursor
				*/
				// Shift func is bullshit
				command = shift_right_string(command, (int)ft_strlen(command) - index, input[0]);
				apply_termcap(DL);
				apply_termcap(RC);
				ft_putstr(PROMPT);
				ft_putstr(command);
				int		test = 0;
				while (test <= index)
				{
					apply_termcap(LE);
					test++;
				}
			}
			ft_putchar(command[a]);
			a++;
			cursor_pos++;
		}
		ft_memset(input, 0, 3);
	}
}

char		*shift_right_string(char *str, int index, char c)
{
	int			a;
	int			b;
	char		*tmp;

	a = 0;
	b = 0;
	tmp = ft_strdup(str);
	while (a != index)
		a++;
	b = a;
	str[b] = c;
	b++;
	while (tmp[a])
	{
		str[b] = tmp[a];
		a++;
		b++;
	}
	free(tmp);
	return (str);
}

void		core2(char **env)
{
	char		input[3];
	char		*command;
	int 		ret_size;
	int 		a;
	int			left;
	int			right;
	int			pos;

	pos = 0;
	if (!(command = (char *)malloc(sizeof(char) * 1024)))
		exit(EXIT_SUCCESS);
	(void)env;
	a = 0;
	apply_termcap(SC);						// SAVE CURSOR POSITION
	ft_memset(command, 0, 3);
	ft_memset(command, 0, 1024);
	ft_putstr(PROMPT);					// PRINT PROMPT
	while ((ret_size = read(0, input, 3)) < 3 && a < 1024)
	{
		//printf("[0] = %d | [1] = %d | [2] = %d\n", input[0], input[1], input[2]);
		if (input[0] == 10)
		{
			apply_termcap(DL);
			apply_termcap(RC);
			ft_putstr(PROMPT);
			ft_putstr(command);
			ft_debug(command);
			ft_putchar('\n');
			// ADD HISTORY
			if (ft_strncmp(command, "exit", 4) == 0)
			{
				free(command);
				free_d_char(env);
			//	while (1);		// CHECK LEAKS
				exit(EXIT_SUCCESS);
			}
			ft_strclr(command);
			ft_strclr(input);
			core(env);
		}
		else if (input[0] == 27 && input[1] == 91 && input[2] == 68)	// LEFT ARROW
		{
			apply_termcap(DL);
			apply_termcap(RC);
			ft_putstr(PROMPT);
			ft_putstr(command);
			if (pos < (int)ft_strlen(command))
				pos++;
		//	ft_debug("POS VALUE");
		//	ft_putnbr(pos);
			ft_strclr(input);
			a -= 2;
			left = 0;
			while (pos > left && left < (int)ft_strlen(command))
			{
				apply_termcap(LE);
				left++;
			}
		}
		else if (input[0] == 27 && input[1] == 91 && input[2] == 67)	// RIGHT ARROW
		{
			apply_termcap(DL);
			apply_termcap(RC);
			ft_putstr(PROMPT);
			ft_putstr(command);
			if (pos <= (int)ft_strlen(command) && pos > 0)
				pos--;
		//	ft_debug("POS VALUE");
		//	ft_putnbr(pos);
			ft_strclr(input);
			a += 2;
			right = 0;
			while (pos > right && right < (int)ft_strlen(command))
			{
				apply_termcap(LE);
				right++;
			}
		}
		//else if (input[0] == 27 && input[1] == 91 && input[2] == 65)
			// UP ARROW - HISTORY
		//else if (input[0] == 27 && input[1] == 91 && input[2] == 66)
			// DOWN ARROW - HISTORY
		else if (input[0] == 127)										// DELETE KEY
		{
			apply_termcap(DL);
			apply_termcap(RC);
			ft_putstr(PROMPT);
			command = shift_left(command, pos);
			ft_putstr(command);
			if (pos <= (int)ft_strlen(command))
				pos++;
			ft_strclr(input);
			a += 2;
			pos--;
			left = 0;
//			ft_debug("POS VALUE");
//			ft_putnbr(pos);
			while (pos > left && left < (int)ft_strlen(command))
			{
				apply_termcap(LE);
				left++;
			}
		}
		else
		{
			if (command[a] == 0)
			{
				command[a] = input[ret_size - 1];
				ft_putchar(command[a]);
			}
			else
			{
				command = shift_right(command, a, input[ret_size - 1]);
				apply_termcap(DL);
				apply_termcap(RC);
				ft_putstr(PROMPT);
				ft_putstr(command);
				left = 0;
				a += 2;
				while (pos > left && left < (int)ft_strlen(command))
				{
					apply_termcap(LE);
					left++;
				}
			}
		}
		a++;
	}
	if (ret_size >= 1024 || a >= 1024)
		ft_debug("Error : The command you wrote is too long.");
}

char		*shift_left(char *command, int pos)
{
	int		a;
	int		char_to_delete;
	char	*res;

	char_to_delete = (int)ft_strlen(command) - 1 - pos;
	a = 0;
	if (!(res = (char *)malloc(sizeof(char) * 1024)))
		exit(EXIT_FAILURE);
	ft_memset(res, 0, 1024);
	while (command[a] && a < char_to_delete)
	{
		res[a] = command[a];
		a++;
	}
	while (command[a + 1])
	{
		res[a] = command[a + 1];
		a++;
	}
	free(command);
	return (res);
}

char		*shift_right(char *command, int pos, char c)
{
	int		a;
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * 1024)))
		exit(EXIT_FAILURE);
	ft_memset(res, 0, 1024);
	a = 0;
	while (a < pos && command[a])
	{
		res[a] = command[a];
		a++;
	}
	res[a] = c;
	while (command[a])
	{
		res[a + 1] = command[a];
		a++;
	}
	free(command);
	return (res);
}
