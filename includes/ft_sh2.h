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
# define ND 5

typedef struct 		s_glob
{
	struct termios	term;
	struct termios	default_term;
	char			*term_name;
	char			**test;
}					t_glob;

t_glob				*glob;

typedef struct		s_char
{
	char			c;
	struct s_char	*next;
	struct s_char	*prev;
}					t_char;

/*
**		INIT
*/

char		**duplicate_environment(char **env);
void		init(void);

/*
**		CORE
*/



/*
**		PARSING
*/

void		parsing(char **env, t_control *history);
char		*shift_right_string(char *str, int index, char c);
char		*shift_left_string(char *str, int index);

/*
**		TERMCAPS
*/

void		apply_termcap(int macro);

/*
**		FREE
*/

void		free_d_char(char **d_char);

#endif
