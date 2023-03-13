/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:03:38 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/13 13:03:40 by jeongmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_command(t_ast *node, t_fd *fd_data)
{
	char	*path;
	char	**command;

	command = ft_split(node->argu, ' ');
	path = find_path(command, fd_data->envp);
	execve(path, command, fd_data->envp);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(node->argu, 2);
	ft_putendl_fd(": command not found: ", 2);
	if (fd_data->fd_flag == -1)
		fd_data->fd_flag = fd_data->pipe_read;
	exit(127);
}

char	*find_path(char **command, char **envp)
{
	char	**path;
	char	*tmp_cmd;
	char	*tmp_av;
	int		flag;
	int		i;

	path = path_checker(envp);
	if (path == NULL)
		exit(1);
	flag = cmd_access(command[0]);
	i = 0;
	tmp_cmd = NULL;
	while (path[i] && flag != 0)
	{
		if (tmp_cmd != NULL)
			free(tmp_cmd);
		tmp_av = combine_path_cmd(command[0]);
		tmp_cmd = ft_strjoin(path[i], tmp_av);
		free(tmp_av);
		flag = cmd_access(tmp_cmd);
		i++;
	}
	ft_free_sp(path);
	return (tmp_cmd);
}

char	*combine_path_cmd(char *cmd)
{
	char	*dup_cmd;
	char	*res;

	dup_cmd = ft_strdup(cmd);
	res = ft_strjoin("/", dup_cmd);
	if (dup_cmd != NULL)
		free(dup_cmd);
	return (res);
}

char	**path_checker(char **envp)
{
	char	**path;
	char	*tmp_path;
	int		i;

	i = 0;
	tmp_path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			tmp_path = ft_strtrim(envp[i], "PATH=");
		i++;
	}
	if (tmp_path == NULL)
		exit(1);
	path = ft_split(tmp_path, ':');
	free(tmp_path);
	return (path);
}

int	cmd_access(char *command)
{
	int	flag;

	flag = access(command, F_OK);
	return (flag);
}
