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

/*
**		INIT
*/

char		**duplicate_environment(char **env);
void		init(void);

/*
**		CORE
*/



/*
**		LEXER
*/

void			lexer(char **env, char *command);
t_control		*add_token(t_control *tokens, char *str, int *a);
t_control		*set_redirection_token_1(t_control *tokens, char *str, int *a);
t_control		*set_redirection_token_2(t_control *tokens, char *str, int *a);
t_control		*set_command_token(t_control *tokens, char *str, int *a);

void			token_tree(t_control *tokens_list, char **env);

/*
**		PARSER & LINE EDITER
*/

void		parsing(char **env, t_control *history);
char		*add_char(char *str, char c, int index, int *a);
char		*delete_key(char *str, int *a, int cursor);
void		move_cursor_sides(char input, int *index, int a, int len);
char		*up_history(int *previous, t_control *history, int *a);
char		*down_history(int *previous, t_control *history, int *a);
void		add_history(t_control *history, char *command, char **env);
char		*init_command(int *a, int *index, int *previous);
char		*shift_right_string(char *str, int index, char c);

void		splitter(char **env, t_control *history, char *command);

char		**str_split(char *str, char sep, int mfree);


/*
**		TERMCAPS
*/

void		apply_termcap(int macro);

/*
**		FREE
*/

void		free_d_char(char **d_char);

/*
**		OTHER
*/

char		**str_split_whitespaces(char *str, int mfree);

#endif
