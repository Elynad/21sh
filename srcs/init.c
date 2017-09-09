/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:00:12 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/07 13:00:18 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

char		**duplicate_environment(char **env)
{
	char		**new_env;
	size_t		size;

	size = 0;
	while (env[size])
		size++;
	if (size == 0)
		return (NULL);
	if (!(new_env = (char **)malloc(sizeof(char *) * (size + 1))))
		exit(EXIT_FAILURE);
	size = 0;
	while (env[size])
	{
		new_env[size] = ft_strdup(env[size]);
		size++;
	}
	new_env[size] = NULL;
	return (new_env);
}

void		init(void)
{
    if ((glob->term_name = getenv("TERM")) == NULL)
        exit(EXIT_FAILURE);
    if (tgetent(NULL, glob->term_name) == -1)
        exit(EXIT_FAILURE);
    if (tcgetattr(0, &glob->term) == -1)
        exit(EXIT_FAILURE);
    if (tcgetattr(0, &glob->default_term) == -1)
        exit(EXIT_FAILURE);
    glob->term.c_lflag &= ~(ICANON);
    glob->term.c_lflag &= ~(ECHO);
    glob->term.c_cc[VMIN] = 1;
    glob->term.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &glob->term) == -1)
       exit(EXIT_FAILURE);
}