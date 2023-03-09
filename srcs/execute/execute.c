/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:14:29 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/07 19:14:31 by jeongmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute(t_ast *node)
{
	t_fd	*fd_data;

	fd_data = init_fd_struct(node);
	execute_pipe(node, fd_data);

}

void	execute_pipe(t_ast *node, t_fd *fd_data)
{
	if (node == NULL)
		return ;
	if (fd_data == NULL)
		return ;
	if (node != NULL)
	{
		if (node->type != PIPE)
			preorder_traversal(&node, fd_data);
	}
	while (fd_data->idx < fd_data->pipe_cnt)
	{
		if (node->right != NULL)
		{
			if (node->right->type == PIPE)
			{
				redir(node, fd_data);
			}
		}
		fd_data->idx++;
	}
}

void	preorder_traversal(t_ast **root, t_fd *fd_data)
{
	if (*root == NULL)
		return ;
	execute_node(*root, fd_data);
	if (*root != NULL)
		preorder_traversal(&(*root)->left, fd_data);
	if (*root != NULL)
	{
		if (*root != PIPE)
			preorder_traversal(&(*root)->right, fd_data);
	}
}

void	execute_node(t_ast *node, t_fd *fd_data)
{
	if (node->type == INPUT)
		execute_input(node, fd_data);
	else if (node->type == OUTPUT)
		execute_output(node, fd_data);
	else if (node->type == HEREDOC)
		execute_heredoc(node, fd_data);
	else if (node->type == APPEND)
		execute_append(node, fd_data);
	else if (node->type == CMD)
		execute_cmd(node, fd_data);
}
