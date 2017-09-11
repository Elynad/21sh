/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_print_tree_prefix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:33:54 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/07 12:37:56 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbt.h"

void		bt_print_tree_prefix(t_btree *tree)
{
	if (tree == NULL)
		return ;
	if (tree->parent != NULL)
	{
		ft_putchar('(');
	//	ft_putnbr(tree->parent->value);
		ft_putstr(tree->parent->str);
		ft_putstr(") -> ");
	//	ft_putnbr(tree->value);
		ft_putstr(tree->str);
		ft_putchar('\n');
	}
	else
	{
		ft_putchar('(');
//		ft_putnbr(tree->value);
		ft_putstr(tree->str);
		ft_putstr(")\n");
	}
	if (tree->bt_left != NULL)
		bt_print_tree_prefix(tree->bt_left);
	if (tree->bt_right != NULL)
		bt_print_tree_prefix(tree->bt_right);
}
