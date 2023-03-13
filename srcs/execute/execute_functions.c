/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:00:33 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/10 18:00:35 by jeongmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_functions(t_ast *node, t_fd *fd_data)
{
	pid_t	pid;

	pid = fork();

	if (pid == -1)
		exit(1);
	else if (pid == 0)
	{
		child_pipe(fd_data);
		if (is_builtin(node) == 0)
			execute_command(node, fd_data);
		else
			execute_command(node, fd_data);
	}
	waitpid(pid, NULL, 0);
	parent_pipe(fd_data);
}

void	child_pipe(t_fd *fd_data)
{
	if (fd_data->pipe_idx > 0)
	{ 	// 현재 pipe가 mid or last라면
		// 파이프 읽기fd가 표준입력이 아니라면 파이프의 값을 읽어와 표준 입력에 넣어줌
		if (fd_data->pipe_read != STDIN_FILENO)
		{
			dup2(fd_data->pipe_read, STDIN_FILENO);
			close(fd_data->pipe_read);
		}
	}
	if (fd_data->idx < fd_data->pipe_cnt - 1)
	{	// 현재 파이프가 last가 아니라면
		// 안 쓰는 파이프의 fd를 닫아주고(안 닫아주면 입력대기에 빠짐)
		if (fd_data->pipe_write != STDOUT_FILENO)
		{
			close(fd_data->fd[0]);
			// 파이프의 쓰기에 결과를 써주고(그래야 다음 파이프에서 쓸 수 있음) 닫아줌
			dup2(fd_data->pipe_write, STDOUT_FILENO);
			close(fd_data->pipe_write);
		}
	}
	// 리다이렉션 타입이 있다면 거기서 읽거나 써줌
	if (fd_data->fd_read != STDIN_FILENO)
		dup2(fd_data->fd_read, STDIN_FILENO);
	if (fd_data->fd_write != STDOUT_FILENO)
		dup2(fd_data->fd_write, STDOUT_FILENO);
}

void	parent_pipe(t_fd *fd_data)
{
	// 파이프가 mid or last라면 pipe_read를 닫아줌
	if (fd_data->pipe_idx > 0)
		close(fd_data->pipe_read);
	if (fd_data->idx < fd_data->pipe_cnt - 1)
	{	// 파이프가 last가 아니라면 pipe_read에 fd[0] 저장(다음 파이프에 연결하기 위해)
		close(fd_data->fd[1]);
		fd_data->pipe_read = fd_data->fd[0];
	}
}

int	is_builtin(t_ast *node)
{
	if (ft_strncmp(node->order, "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(node->order, "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(node->order, "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(node->order, "env", 3) == 0)
		return (1);
	else if (ft_strncmp(node->order, "export", 6) == 0)
		return (1);
	else if (ft_strncmp(node->order, "unset", 5) == 0)
		return (1);
	else if (ft_strncmp(node->order, "exit", 4) == 0)
		return (1);
	return (0);
}
