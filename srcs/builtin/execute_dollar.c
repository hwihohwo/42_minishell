/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:31:58 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/11 19:28:45 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	dollar_length_count(char *line, int i)
{
	int	count;

	count = 0;
	while (!ft_isspace(line[i]) && line[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	*extract_env(char *env)
{
	int		i;
	int		sav;
	int		count;
	char	*ret;

	i = 0;
	count = 0;
	while (env[i] != '=' && env[i])
		i++;
	if (env[i] == '\0')
		return (0);
	else
	{
		i++;
		sav = i;
		count = ft_strlen(&env[i]);
		ret = (char *)ft_calloc(count + 1, sizeof(char));
		if (ret == 0)
			error_exit(0);
		i = 0;
		while (i < count)
			ret[i++] = env[sav++];
		return (ret);
	}
}

char	*make_to_one_string(char *before_start, char *env_value, \
char *after_end)
{
	char	*ret;
	char	*temp;

	if (env_value == 0)
	{
		ret = ft_strjoin(before_start, after_end);
		if (ret == 0)
			error_exit(0);
		free(before_start);
		free(after_end);
	}
	else
	{
		temp = ft_strjoin(before_start, env_value);
		if (temp == 0)
			error_exit(0);
		free(before_start);
		free(env_value);
		ret = ft_strjoin(temp, after_end);
		if (ret == 0)
			error_exit(0);
		free(temp);
		free(after_end);
	}
	return (ret);
}

char	*replace_dollar(char *line, char *env_value, int start, int end)
{
	char	*after_end;
	char	*before_start;
	int		i;

	i = 0;
	before_start = (char *)ft_calloc(start - i + 1, sizeof(char));
	if (before_start == 0)
		error_exit(0);
	while (i < start)
	{
		before_start[i] = line[i];
		i++;
	}
	after_end = (char *)ft_calloc(ft_strlen(line) - end + 1, sizeof(char));
	if (after_end == 0)
		error_exit(0);
	i = 0;
	while (line[end])
		after_end[i++] = line[end++];
	free(line);
	return (make_to_one_string(before_start, env_value, after_end));
}

char	*execute_dollar(char *line, int i, char **env)
{
	int		count;
	char	*name;
	char	*env_value;
	int		j;
	int		start;

	j = 0;
	if (line[i] == '$')
		i++;
	env_value = 0;
	start = i;
	count = dollar_length_count(line, i);
	name = (char *)ft_calloc(count, sizeof(char));
	if (name == 0)
		error_exit(0);
	while (j < count)
		name[j++] = line[i++];
	name[j] = '\0';
	j = -1;
	while (env[++j])
		if (ft_strncmp(name, env[j], ft_strlen(name)) == 0)
			env_value = extract_env(env[j]);
	return (replace_dollar(line, env_value, start, i));
}
