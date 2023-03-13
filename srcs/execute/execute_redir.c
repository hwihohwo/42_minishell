/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:14:54 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/10 13:14:56 by jeongmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_input(t_ast *node, t_fd *fd_data)
{
	int	tmp_fd;

	tmp_fd = open(node->argu, O_RDONLY);
	if (tmp_fd == -1)
	{
		// 적절한 에러처리가 필요
		// -1을 dup2하면 bad file descriptor 에러가 발생하기 때문
		
	}
	else
	{
		if (fd_data->fd_read == STDIN_FILENO)
			fd_data->fd_read = tmp_fd;
	}
}

void	execute_output(t_ast *node, t_fd *fd_data)
{
	fd_data->fd_write = open(node->argu, O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

void	execute_heredoc(t_ast *node, t_fd *fd_data)
{
	char	*tmp;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(1);
	while (1)
	{
		tmp = readline("> "); // 혹은 readline?
		if (tmp == NULL || \
		(ft_strncmp(tmp, node->argu, ft_strlen(node->argu)) == 0 && \
		tmp[ft_strlen(node->argu)] == '\n'))
			break ;
		ft_putendl_fd(tmp, fd[1]);
		free(tmp);
	}
	free(tmp);
	close(fd[1]);
	fd_data->fd_read = fd[0];
}

void	execute_append(t_ast *node, t_fd *fd_data)
{
	fd_data->fd_write = open(node->argu, O_WRONLY | O_CREAT | O_APPEND, 0644);
}
