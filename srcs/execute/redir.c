/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:31:00 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/09 18:31:08 by jeongmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	child_process(t_ast *node, t_fd *fd_data, int fd_input, int fd_output)
{
	dup2(fd_input, STDIN_FILENO);
	dup2(fd_output, STDOUT_FILENO);
	close_pipe(fd_data);
	if (fd_data->fd_flag == -1)
		exit(1);
	preorder_traversal(&node, fd_data);
}

void	redir(t_ast *node, t_fd *fd_data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		err_check("fork error", EXIT_FAILURE);
	else if (pid == 0)
	{
		if (fd_data->idx == 0)
			child_process(node, fd_data, fd_data->fd_input, fd_data->fd[1]);
		else if (fd_data->idx == fd_data->pipe_cnt)
			child_process(node, fd_data, fd_data->fd[2 * fd_data->idx - 2], \
			fd_data->fd_output);
		else
			child_process(node, fd_data, fd_data->fd[2 * fd_data->idx - 2], \
			fd_data->fd[2 * fd_data->idx + 1]);
	}
}

void	close_pipe(t_fd *fd_data)
{
	int	i;

	i = 0;
	while (i < 2 * (fd_data->pipe_cnt))
	{
		close(fd_data->fd[i]);
		i++;
	}
}
