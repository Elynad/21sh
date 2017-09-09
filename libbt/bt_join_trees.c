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

t_btree			*bt_join_trees(t_btree *left, t_btree *right, int node)
{
	t_btree		*tree;

	tree = bt_new_tree(node);
	tree->bt_left = left;
	tree->bt_right = right;
	if (left != NULL)
		left->parent = tree;
	if (right != NULL)
		right->parent = tree;
	return (tree);
}
