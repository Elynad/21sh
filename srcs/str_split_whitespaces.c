/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split_whitespaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 23:07:39 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/25 00:25:36 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

static int		get_spaces(char *str)
{
	int			sp;
	int			i;

	sp = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		if (str[i] && (str[i] == ' ' || str[i] == '\t'))
		{
			sp++;
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
				i++;
		}
		else
			i++;
	}
	if (str[i - 1] && (str[i - 1] == ' ' || str[i - 1] == '\t'))
		sp--;
	return (sp + 1);
}

static char		*fill_str(char *str, int *index)
{
	int		a;
	char	*s1;

	a = 0;
	while (str[*index] && (str[*index] == ' ' || str[*index] == '\t'))
		(*index)++;
	a = *index;
	while (str && str[a] && str[a] != ' ' && str[a] != '\t')
		a++;
	if (a == *index)
		return (NULL);
	if (!(s1 = (char *)malloc(sizeof(char) * (a - *index + 1))))
		exit(EXIT_FAILURE);
	a = 0;
	while (str[*index] && str[*index] != ' ' && str[*index] != '\t')
	{
		s1[a] = str[*index];
		a++;
		(*index)++;
	}
	s1[a] = '\0';
	return (s1);
}

char			**str_split_whitespaces(char *str, int mfree)
{
	char		**split;
	int			index;
	int			spaces;
	int			size;

	index = 0;
	spaces = get_spaces(str);
	if (!(split = (char **)malloc(sizeof(char *) * (spaces + 1))))
		exit(EXIT_FAILURE);
	size = spaces;
	spaces = 0;
	while (str[index])
	{
		split[spaces] = fill_str(str, &index);
		spaces++;
		index++;
	}
	split[spaces] = NULL;
	if (mfree == 1)
	{
		free(str);
		str = NULL;
	}
	return (split);
}
