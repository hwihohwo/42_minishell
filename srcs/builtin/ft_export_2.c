/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:48:23 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/14 19:46:19 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_env_list_export(char **env, char *argu)
{
	int	j;
	int	length;

	j = 0;
	length = ft_strlen_exp(argu);
	while (env[j])
	{
		if (!ft_strncmp(env[j], argu, length) && (env[j][length] == '=' || \
		env[j][length]))
		{
			replace_env_value(&env[j], argu);
			return (1);
		}
		j++;
	}
	return (0);
}

char	**make_new_env(char **env, char *argu)
{
	int		i;
	int		count;
	char	**ret;
	char	*temp;
	char	*pre_fix;

	i = -1;
	count = 0;
	pre_fix = "declare -x ";
	while (env[count])
		count++;
	ret = (char **)ft_calloc(count + 2, sizeof(char *));
	if (ret == 0)
		error_exit(0);
	while (++i < count)
		ret[i] = env[i];
	temp = add_double_quote(argu);
	ret[i++] = ft_strjoin(pre_fix, temp);
	if (ret[i - 1] == 0)
		error_exit(0);
	free(temp);
	free_export_double_array(env);
	order_env(ret);
	return (ret);
}

void	free_double_array(char **argu)
{
	int	i;

	i = 0;
	if (argu != 0)
	{
		while (argu[i])
			free(argu[i++]);
		free(argu);
	}
}

int	split_and_check(char ***argu, t_tokendata *tokendata, char **env)
{
	int	j;

	j = 0;
	*argu = ft_split(tokendata->argu, ' ');
	if (*argu == 0)
		error_exit(0);
	if (!(*argu)[1])
	{
		while (env[j])
			ft_printf("%s\n", env[j++]);
		return (0);
	}
	return (1);
}

void	order_env(char **env)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (env[i])
	{
		j = i + 1;
		while (env[j])
		{
			if (ft_strncmp(env[i], env[j], ft_strlen(env[i]) + 1) > 0)
			{
				temp = env[i];
				env[i] = env[j];
				env[j] = temp;
			}
			j++;
		}
		i++;
	}
}
