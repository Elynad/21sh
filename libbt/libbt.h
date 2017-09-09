/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:24:25 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/07 12:47:39 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBT_H

# define LIBBT_H

# include "../libft/libft.h"

typedef struct			s_btree
{
	int					value;
	struct s_btree		*bt_left;
	struct s_btree		*bt_right;
	struct s_btree		*parent;
}						t_btree;

t_btree					*bt_new_tree(int value);
void					bt_clean_tree(t_btree *tree);
t_btree					*bt_join_trees(t_btree *left, t_btree *right, int node);
void					bt_print_tree_prefix(t_btree *tree);
int						bt_count_tree_nodes(t_btree *tree);

#endif
