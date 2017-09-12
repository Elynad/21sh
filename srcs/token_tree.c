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
	tokens_list = unset_all(tokens_list);
	tree = create_root_tree(tokens_list);
	ft_debug("CREATION DONE");
	bt_print_tree_prefix(tree);
	ft_debug("PRINTING DONE");
}

t_btree		*create_root_tree(t_control *tokens_list)
{
	int			type;
	t_btree		*root;
	t_lst		*tmp;

	ft_debug("Begin, creating root tree, tokens_list value");
	dll_print_list(tokens_list, '\t');
	ft_putchar('\n');
	tmp = tokens_list->begin;
	type = get_type(tokens_list);
	if (!(root = malloc(sizeof(t_btree))))
		exit(EXIT_FAILURE);
	ft_bzero(root, sizeof(t_btree));
	root->parent = NULL;
	root->bt_left = NULL;
	root->bt_right = NULL;
	while (tmp != NULL && tmp->type != type)
		tmp = tmp->next;
	if (tmp)
	{
		root->str = ft_strdup(tmp->name);
	//	tmp->is_set = 1;
		ft_debug("Create left root tree");
		root->bt_left = create_tree(root, create_left_list(tmp));
		ft_debug("Create right root tree");
		root->bt_right = create_tree(root, create_right_list(tmp));
	}
	dll_clear_list(tokens_list);
	return (root);
}

t_btree		*create_tree(t_btree *root, t_control *tokens_list)
{
	int			type;
	t_control	*left_list;
	t_control	*right_list;
	t_btree		*tree;
	t_lst		*tmp;

	if (tokens_list->length < 1)
	{
		ft_debug("List is empty");
		return (NULL);
	}
	ft_debug("Begin of CREATE_TREE, tokens_list value");
	dll_print_list(tokens_list, '\t');
	ft_putchar('\n');
	tree = NULL;
	type = get_type(tokens_list);
	ft_putstr("Looking for type == ");
	ft_putnbr(type);
	ft_putchar('\n');
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
	//	tmp->is_set = 1;
		left_list = create_left_list(tmp);
		if (left_list)
		{
			ft_debug("Going to create left tree");
			tree->bt_left = create_tree(tree, create_left_list(tmp));
		}
		else
		{
			tree->bt_left = NULL;
			ft_debug("No left list, no left tree");
		}
		right_list = create_right_list(tmp);
		if (right_list)
		{
			ft_debug("Going to create right tree");
			tree->bt_right = create_tree(tree, create_right_list(tmp));
		}
		else
		{
			tree->bt_right = NULL;
			ft_debug("No right list, no right tree");
		}
	}
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
		if (tmp->type == type)// && tmp->is_set == 0)
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

t_control	*unset_all(t_control *tokens_list)
{
	t_lst	*tmp;

	tmp = tokens_list->begin;
	tmp = tmp->next;
	while (tmp != NULL)
	{
//		tmp->is_set = 0;
		tmp = tmp->next;
	}
	return (tokens_list);
}
