/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:49:47 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/15 11:49:10 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*cpy;

	cpy = *alst;
	while (cpy)
	{
		tmp = cpy->next;
		del(cpy->content, cpy->content_size);
		free(cpy);
		cpy = tmp;
	}
	*alst = NULL;
}
