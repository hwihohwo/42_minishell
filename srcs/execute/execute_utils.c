/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:21:35 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/09 18:21:38 by jeongmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	count_pipe(t_ast *node, t_fd *fd_data)
{
	t_ast	*tmp;

	tmp = node;
	fd_data->pipe_cnt++;
	while (tmp->right != NULL)
	{
		if (tmp->type == PIPE)
			fd_data->pipe_cnt++;
		tmp = tmp->right;
	}
}

void	free_node(t_ast **node)
{
	if ((*node)->type == PIPE)
		return ;
	else if ((*node)->type == CMD)
		return ;
	else if ((*node)->type == REDIR)
		return ;
	else
	{
		(*node)->order = NULL;
		(*node)->argu = NULL;
	}
}

void	free_tree(t_ast **node)
{
	if ((*node)->left != NULL)
		free_tree(&(*node)->left);
	if ((*node)->right != NULL)
		free_tree(&(*node)->right);
	free_node(node);
	free(*node);
}

void	execute_free(t_ast *node, t_fd *fd_data)
{
	free(fd_data);
	free_tree(&node);
}
