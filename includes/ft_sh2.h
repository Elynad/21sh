/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:56:21 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/07 12:56:25 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH2_H

# define FT_SH2_H

# include "../libft/libft.h"
# include "../libdll/libdll.h"
# include "../libbt/libbt.h"
# include <termios.h>
# include <term.h>
# include <curses.h>

# define PROMPT "mameyer's 21sh $> "
# define SC 1
# define DL 2
# define RC 3
# define LE 4

typedef struct 		s_glob
{
	struct termios	term;
	struct termios	default_term;
	char			*term_name;
	char			**test;
}					t_glob;

t_glob				*glob;

/*
**		INIT
*/

char		**duplicate_environment(char **env);
void		init(void);

/*
**		CORE
*/

void		core(char **env);

char		*shift_right(char *command, int pos, char c);

/*
**		TERMCAPS
*/

void		apply_termcap(int macro);

/*
**		FREE
*/

void		free_d_char(char **d_char);

#endif
