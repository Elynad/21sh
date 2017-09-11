/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:48:36 by mameyer           #+#    #+#             */
/*   Updated: 2017/08/24 23:15:56 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

static int		get_spaces(char *str, char sep)
{
	int			sp;
	int			i;

	sp = 0;
	i = 0;
	while (str[i] && str[i] == sep)
		i++;
	while (str[i])
	{
		if (str[i] && str[i] == '"')
		{
			i++;
			while (str[i] && str[i] != '"')
				i++;
			i++;
		}
		else if (str[i] && str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			i++;
		}
		else if (str[i] && str[i] == sep)
		{
			sp++;
			while (str[i] && str[i] == sep)
				i++;
		}
		else
			i++;
	}
	if (str[i - 1] && str[i - 1] == sep)
		sp--;
	return (sp + 1);
}

static char		*fill_str(char *str, int *index, char sep)
{
	int		a;
	char	*s1;

	a = 0;
	while (str[*index] && str[*index] == sep)
		(*index)++;
	a = *index;
	while (str && str[a] && str[a] != sep && str[a] != '\0')
	{
		if (str[a] && str[a] == '"')
		{
			a++;
			while (str[a] && str[a] != '"')
				a++;
			a++;
		}
		else if (str[a] && str[a] == '\'')
		{
			a++;
			while (str[a] && str[a] != '\'')
				a++;
			a++;
		}
		a++;
	}
	if (a == *index)
		return (NULL);
	if (!(s1 = (char *)malloc(sizeof(char) * (a - *index + 1))))
		exit(EXIT_FAILURE);
	a = 0;
	while (str[*index] && str[*index] != sep)
	{
		if (str[*index] && str[*index] == '\'')
		{
			s1[a] = str[*index];
			a++;
			(*index)++;
			while (str[*index] && str[*index] != '\'')
			{
				s1[a] = str[*index];
				a++;
				(*index)++;
			}
			(*index)++;
		}
		if (str[*index] && str[*index] == '"')
		{
			s1[a] = str[*index];
			a++;
			(*index)++;
			while (str[*index] && str[*index] != '"')
			{
				s1[a] = str[*index];
				a++;
				(*index)++;
			}
			(*index)++;
		}
		else
		{
			s1[a] = str[*index];
			a++;
			(*index)++;
		}
	}
	s1[a] = '\0';
	return (s1);
}

char			**str_split(char *str, char sep, int mfree)
{
	char		**split;
	int			index;
	int			spaces;
	int			size;

	index = 0;
	spaces = get_spaces(str, sep);
	if (!(split = (char **)malloc(sizeof(char *) * (spaces + 1))))
		exit(EXIT_FAILURE);
	size = spaces;
	spaces = 0;
	while (str[index])
	{
		split[spaces] = fill_str(str, &index, sep);
		spaces++;
	}
	split[spaces] = NULL;
	if (mfree == 1)
	{
		free(str);
		str = NULL;
	}
	return (split);
}
