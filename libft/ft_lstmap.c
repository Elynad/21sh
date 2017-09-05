/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:30:16 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/15 11:56:13 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*cpy;
	t_list		*tmp;
	t_list		*ptr;

	cpy = NULL;
	while (lst)
	{
		if (!(tmp = (t_list *)malloc(sizeof(t_list) * 1)))
			return (NULL);
		tmp = f(lst);
		if (!cpy)
		{
			cpy = ft_lstnew(tmp->content, tmp->content_size);
			ptr = cpy;
		}
		else
		{
			cpy->next = ft_lstnew(tmp->content, tmp->content_size);
			cpy = cpy->next;
		}
		lst = lst->next;
	}
	free(tmp);
	return (ptr);
}
