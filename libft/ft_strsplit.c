/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:30:27 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/15 15:51:56 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char *s, char c)
{
	int		w;

	if (s && (ft_strlen(s)) > 0)
	{
		w = 1;
		while (*s)
		{
			if (*s != c)
				++s;
			else
			{
				++w;
				++s;
			}
		}
		return (w);
	}
	return (0);
}

static int		ft_word_len(char *str, char c, int index)
{
	int		i;

	i = index;
	while (str[i] && str[i] != c)
		++i;
	return (i - index);
}

static char		**ft_strsplit_main(char **res, char *s, char c, int tbsz)
{
	int		size;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	k = 0;
	while (++i < tbsz && s[k])
	{
		size = ft_word_len(s, c, k);
		if ((res[i] = ft_strnew(size)))
		{
			while (++j < size && s[k])
				res[i][j] = s[k++];
			j = -1;
			if (s[k] == c)
				k++;
		}
		else
			return (NULL);
	}
	res[i] = NULL;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		words;

	if (s && c)
	{
		i = 0;
		j = 0;
		s = ft_del_fb((char *)s, c);
		words = ft_count_words((char *)s, c);
		if (!(res = (char **)malloc(sizeof(char *) * (words + 1))))
			return (NULL);
		res = ft_strsplit_main(res, (char *)s, c, words);
		return (res);
	}
	return (NULL);
}
