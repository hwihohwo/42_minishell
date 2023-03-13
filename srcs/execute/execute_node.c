/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:59:53 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/10 17:59:54 by jeongmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_node(t_ast *node, t_fd *fd_data)
{
	if (node->type == PIPE)
		execute_pipe(fd_data);
	else if (node->type == INPUT)
		execute_input(node, fd_data);
	else if (node->type == OUTPUT)
		execute_output(node, fd_data);
	else if (node->type == HEREDOC)
		execute_heredoc(node, fd_data);
	else if (node->type == APPEND)
		execute_append(node, fd_data);
	else if (node->type == CMD)
		execute_cmd(fd_data);
	else if (node->type == SCMD && ft_strncmp(node->order, "S", 1))
		execute_simple_cmd(node, fd_data);
}

void	execute_pipe(t_fd *fd_data)
{
	fd_data->pipe_idx++;
	if (fd_data->pipe_idx < fd_data->pipe_cnt - 1)
	{
		if (pipe(fd_data->fd) == -1)
			exit(1);
		fd_data->pipe_write = fd_data->fd[1];
	}
}
/*
void	execute_pipe(t_ast *node, t_fd *fd_data)
{
	fd_data->pipe_idx++;
	ft_putstr_fd(node->order, 2);
	if (fd_data->pipe_idx < fd_data->pipe_cnt - 1)
	{
//		if (node->right->type == PIPE)
//		{
			if (pipe(fd_data->fd) == -1)
				exit(1);
//			fd_data->pipe_write = fd_data->fd[1];
//		}
		fd_data->pipe_write = fd_data->fd[1];
	}
	ft_putendl_fd(node->order, 2);
}
*/

/*
	if (node->right != NULL)
	{
		if (node->right->type == PIPE)
		{
			if (pipe(fd_data->fd) == -1)
				exit(1);
		}
		fd_data->pipe_write = fd_data->fd[1];
	}
*/
void	execute_cmd(t_fd *fd_data)
{
	if (fd_data->fd_read != STDIN_FILENO)
		dup2(STDIN_FILENO, fd_data->fd_read);
	if (fd_data->fd_read != STDOUT_FILENO)
		dup2(STDOUT_FILENO, fd_data->fd_write);
}

void	execute_simple_cmd(t_ast *node, t_fd *fd_data)
{
	execute_functions(node, fd_data);
}

