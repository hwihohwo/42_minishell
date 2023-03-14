/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:22:26 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/14 15:09:56 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strlen_exp(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=' && !ft_isspace(str[i]))
		i++;
	return (i);
}

char	*calloc_for_quote(char *str)
{
	int		count;
	int		i;
	char	*ret;

	i = 0;
	count = 0;
	while (str[i] && str[i - 1] != '=')
	{
		i++;
		count++;
	}
	while (str[i] == '\"')
		i++;
	while (str[i] != '\"' && str[i])
	{
		i++;
		count++;
	}
	ret = ft_calloc(count + 3, sizeof(char));
	if (ret == 0)
		error_exit(0);
	return (ret);
}

char	*add_double_quote(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = calloc_for_quote(str);
	while (str[i] && str[i - 1] != '=')
		ret[j++] = str[i++];
	while (str[i])
	{
		while (str[i] == '\"')
			i++;
		ret[j++] = '\"';
		while (str[i] != '\"' && str[i])
			ret[j++] = str[i++];
		ret[j] = '\"';
	}
	return (ret);
}

void	replace_env_value(char **env, char *argu)
{
	int		i;
	char	*pre_fix;
	char	*temp;

	i = 0;
	pre_fix = "declare -x ";
	temp = add_double_quote(argu);
	free(*env);
	*env = ft_strjoin(pre_fix, temp);
	if (*env == 0)
		error_exit(0);
	free(temp);
}

int	ft_export(t_tokendata *tokendata, char **env)
{
	int		i;
	int		result;
	char	**argu;

	i = 1;
	result = 0;
	if (!split_and_check(&argu, tokendata, env))
		return (0);
	while (argu[i])
	{
		if (!ft_isalpha(argu[i][0]) || argu[i][0] != '_')
		{
			result = 1;
			i++;
			continue ;
		}
		if (check_env_list(env, argu[i]) == 1)
		{
			i++;
			continue ;
		}
		env = make_new_env(env, argu[i++]);
	}
	free_export_double_array(argu);
	return (result);
}
