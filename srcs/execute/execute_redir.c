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
	fd_data->fd_read = tmp_fd;
	if (tmp_fd == -1)
	{	
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(node->argu, 2);
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
