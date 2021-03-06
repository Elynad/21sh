/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 17:27:30 by hublanc           #+#    #+#             */
/*   Updated: 2017/09/13 19:47:10 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "line_editor.h"

typedef struct		s_token
{
	char			*token;
	enum
	{
		NONE,
		WORD,
		QUOTE,
		REDIRECTION,
		PIPE,
		SEMI_COLON,
		IO_NUMBER,
		}			e_type;
	struct s_token	*next;
}					t_token;

typedef struct		s_node
{
	int				value;
	char			*token;
	int				wait;
	int				pipe;
	int				end_pipe;
	int				in;
	int				out;
	int				in_pipe;
	int				redir_r;
	int				redir_l;
	int				heredoc;
	int				aggre;
	int				*aggre_in_nb;
	char			**aggre_in_w;
	int				*aggre_out_nb;
	char			**aggre_out_w;
	char			*heredoc_str;
	int				*fd_out;
	int				*fd_out_io;
	int				*fd_in;
	int				*fd_in_io;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

/*
**	Routine.c
*/
void		routine(char *cmd, char ***env, t_control **history);

/*
**	Exec.c
*/
int			check_cmd(char **tab, char **env, t_node *tree);
void		get_cmd(t_node *tree, char ***env, int *status, t_control **hist);

/*
**	Ft_cmdsplit.c
*/
char		**ft_cmdsplit(char *str);

#endif
