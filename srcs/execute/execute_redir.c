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
		ft_putstr_fd("minishell: ", 2); // "<a ls -l" 의 결과 = bash: a: No such file or directory
		ft_putstr_fd(node->argu, 2);
	}
	else
	{
		if (fd_data->fd_read != STDIN_FILENO)
			close(fd_data->fd_read);
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
	if (fd_data->fd_read != STDIN_FILENO)
		close(fd_data->fd_read);
	while (1)
	{	
		tmp = readline("> ");
		if (tmp == NULL || \
		((ft_strncmp(tmp, node->argu, ft_strlen(node->argu)) == 0) && \
		ft_strlen(tmp) == ft_strlen(node->argu)))
		{
			free(tmp);
			break;
		}
		ft_putendl_fd(tmp, fd[1]);
		free(tmp);
	}
	close(fd[1]);
	fd_data->fd_read = fd[0];
}

void	execute_append(t_ast *node, t_fd *fd_data)
{
	fd_data->fd_write = open(node->argu, O_WRONLY | O_CREAT | O_APPEND, 0644);
}
