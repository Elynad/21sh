/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_count_tree_nodes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:38:06 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/07 12:42:53 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbt.h"

int			bt_count_tree_nodes(t_btree *tree)
{
	if (tree == NULL)
		return (0);
	return (bt_count_tree_nodes(tree->bt_left)
			+ bt_count_tree_nodes(tree->bt_right) + 1);
}
