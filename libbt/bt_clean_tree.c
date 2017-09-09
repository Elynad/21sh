/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_clean_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:28:56 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/07 12:30:26 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbt.h"

void			bt_clean_tree(t_btree *tree)
{
	if (tree == NULL)
		return ;
	bt_clean_tree(tree->bt_left);
	bt_clean_tree(tree->bt_right);
	free(tree);
}
