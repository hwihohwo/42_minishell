/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:52:22 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/14 19:58:23 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**make_new_env_list(char **env, int old_num)
{
	int		i;
	int		count;
	char	**ret;

	i = 0;
	count = env_new_num(env, old_num);
	ret = (char **)ft_calloc(count + 1, sizeof(char *));
	if (ret == 0)
		error_exit(0);
	count = 0;
	while (i < old_num)
	{
		if (env[i] == 0)
		{
			i++;
			continue ;
		}
		ret[count++] = env[i++];
	}
	return (ret);
}

void	check_env_list_unset(char **env, char *argu)
{
	int	j;
	int	length;

	j = 0;
	length = ft_strlen(argu);
	while (env[j])
	{
		if (ft_strncmp(env[j], argu[i], length) == 0 \
		&& (env[j][length] == '=' || !env[j][length]))
			delete_env(&env[j]);
		j++;
	}
}

void	free_old_env_unset(char **env, int old_num)
{
	int	i;

	i = 0;
	if (env != 0)
	{
		while (i < old_num)
		{
			if (env[i] != 0)
				free(env[i]);
			i++;
		}
		free(env);
	}
}

int	ft_unset(t_tokendata *tokendata, char **env)
{
	int		i;
	char	**argu;
	int		count;
	char	**temp;

	i = 0;
	count = env_num(env);
	argu = ft_split(tokendata->argu, ' ');
	if (argu == 0)
		error_exit(0);
	while (argu[i])
	{
		check_env_list_unset(env, argu[i]);
		i++;
	}
	temp = make_new_env_list(env, count);
	free_old_env_unset(env, count);
	env = temp;
	return (0);
}
