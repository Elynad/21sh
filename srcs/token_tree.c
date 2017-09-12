/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:50:28 by mameyer           #+#    #+#             */
/*   Updated: 2017/09/11 16:50:30 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"

void		token_tree(t_control *tokens_list, char **env)
{
	t_btree		*tree;

	(void)env;
	tree = NULL;
	tree = create_root_tree(tokens_list);
//	while (1);
	bt_print_tree_prefix(tree);
	bt_clean_tree(tree);			// FREE TREE
}

t_btree		*create_root_tree(t_control *tokens_list)
{
	int			type;
	t_btree		*root;
	t_lst		*tmp;
	t_control	*left_list;
	t_control	*right_list;

	left_list = NULL;
	right_list = NULL;
	tmp = tokens_list->begin;
	type = get_type(tokens_list);
	if (!(root = malloc(sizeof(t_btree))))
		exit(EXIT_FAILURE);
	ft_bzero(root, sizeof(t_btree));
	while (tmp != NULL && tmp->type != type)
		tmp = tmp->next;
	if (tmp)
	{
		root->str = ft_strdup(tmp->name);
		if (tokens_list->length > 1)
		{
			left_list = create_left_list(tmp);
			root->bt_left = create_tree(root, left_list);
			right_list = create_right_list(tmp);
			root->bt_right = create_tree(root, right_list);
			dll_clear_list(left_list);
			dll_clear_list(right_list);
		}
	}
	tmp = NULL;
	dll_clear_list(tokens_list);
//	while (1);
	return (root);
}

t_btree		*create_tree(t_btree *root, t_control *tokens_list)
{
	int			type;
	t_control	*left_list;
	t_control	*right_list;
	t_btree		*tree;
	t_lst		*tmp;

	left_list = NULL;
	right_list = NULL;
	if (tokens_list->length < 1)
		return (NULL);
	tree = NULL;
	type = get_type(tokens_list);
	tmp = tokens_list->begin;
	while (tmp && tmp->type != type)
		tmp = tmp->next;
	if (tmp)
	{
		if (!(tree = malloc(sizeof(t_btree))))
			exit(EXIT_FAILURE);
		ft_bzero(tree, sizeof(t_btree));
		tree->parent = root;
		tree->str = ft_strdup(tmp->name);
		left_list = create_left_list(tmp);
		if (left_list)
			tree->bt_left = create_tree(tree, left_list);
		else
			tree->bt_left = NULL;
		right_list = create_right_list(tmp);
		if (right_list)
			tree->bt_right = create_tree(tree, right_list);
		else
			tree->bt_right = NULL;
		dll_clear_list(right_list);
		dll_clear_list(left_list);

	}
	else
		dll_clear_list(tokens_list);
	return (tree);
}

int			get_type(t_control *tokens_list)
{
	int		type;

	type = UNSET;
	if (check_disp(tokens_list, AND))
		type = AND;
	else if (check_disp(tokens_list, PIPE))
		type = PIPE;
	else if (check_disp(tokens_list, REDIRECTION))
		type = REDIRECTION;
	else if (check_disp(tokens_list, COMMAND))
		type = COMMAND;
	return (type);	
}

int			check_disp(t_control *tokens_lists, int type)
{
	t_lst		*tmp;

	tmp = NULL;
	tmp = tokens_lists->begin;
	while (tmp != NULL)
	{
		if (tmp->type == type)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_control	*create_right_list(t_lst *elem)
{
	t_control	*right_list;

	right_list = NULL;
	elem = elem->next;
	while (elem != NULL)
	{
		right_list = dll_add_new_elem_end(right_list, elem->name);
		right_list->end->type = elem->type;
		elem = elem->next;
	}
	return (right_list);
}

t_control	*create_left_list(t_lst *elem)
{
	t_control	*left_list;

	left_list = NULL;
	elem = elem->prev;
	while (elem != NULL)
	{
		left_list = dll_add_new_elem_frnt(left_list, elem->name);
		left_list->begin->type = elem->type;
		elem = elem->prev;
	}
	return (left_list);
}
