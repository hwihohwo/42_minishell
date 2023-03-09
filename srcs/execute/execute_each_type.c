/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_each_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:55:19 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/09 16:55:21 by jeongmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_input(t_ast *node, t_fd *fd_data)
{
	fd_data->fd_input = open(node->argu, O_RDONLY);
}

void	execute_output(t_ast *node, t_fd *fd_data)
{
	fd_data->fd_output = open(node->argu, O_WRONLY);
}

void	execute_heredoc(t_ast *node, t_fd *fd_data)
{
	char	*tmp;

	fd_data->heredoc = 1;
	fd_data->fd_input = open("here_doc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_data->fd_input == -1)
		perror("file open error");
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		tmp = get_next_line(STDIN_FILENO); // 혹은 readline?
		if (tmp == NULL || \
		(ft_strncmp(tmp, node->argu, ft_strlen(node->argu)) == 0 && \
		tmp[ft_strlen(node->argu)] == '\n'))
			break ;
		write(fd_data->fd_input, tmp, ft_strlen(tmp));
		free(tmp);
	}
	free(tmp);
}

void	execute_append(t_ast *node, t_fd *fd_data)
{

}

void	execute_cmd(t_ast *node, t_fd *fd_data)
{

}
