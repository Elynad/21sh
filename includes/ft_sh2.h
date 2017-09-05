/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 05:31:22 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/04 05:34:41 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH2_H

# define FT_SH2_H

# include "../libft/libft.h"
# include "../libdll/libdll.h"
# include <sys/termios.h>
# include <sys/ioctl.h>
# include <term.h>
# include <stdio.h>				// TESTS

typedef struct			s_global
{
	struct termios		term;
	struct termios		default_term;
	char				*term_name;
}						t_global;

/*
**		INIT
*/

t_control		*get_env(t_control *env, char **environment);
void			init(t_global *glob);

/*
**		LEXING AND PARSING
*/

int 			check_str(char *str);
t_control		*lexer(char *str);
t_control		*get_until_next_sq(char *str, int *a, t_control *tokens);
t_control		*get_until_next_dq(char *str, int *a, t_control *tokens);

/*
**		CORE
*/

void			core(t_control *env, t_global *glob);

/*
**		PRINT
*/

void			print_list(t_control *control);

/*
**		ERRORS
*/

void			empty_env(void);

#endif

/*
**		mkdir "test ; 1" ; ls -l | cat -e
*/