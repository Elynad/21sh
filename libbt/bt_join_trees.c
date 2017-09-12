/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_join_trees.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:30:37 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/07 12:33:15 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbt.h"

t_btree			*bt_join_trees(t_btree *left, t_btree *right, t_btree *root)
{
	root->bt_left = left;
	root->bt_right = right;
	if (left != NULL)
		left->parent = root;
	if (right != NULL)
		right->parent = root;
	return (root);
}
