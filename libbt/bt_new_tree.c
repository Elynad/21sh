/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_new_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:25:53 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/07 12:48:18 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbt.h"

t_btree			*bt_new_tree(char *str)
{
	t_btree			*tree;

	if (!(tree = malloc(sizeof(t_btree))))
		exit(EXIT_FAILURE);
	tree->str = str;
	tree->bt_left = NULL;
	tree->bt_right = NULL;
	tree->parent = NULL;
	return (tree);
}
