/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line_setting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:23:37 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/11 19:31:35 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	meet_double_quote(t_flags *flag, char *line)
{
	if (flag->d_quote_flag == 1)
	{
		flag->d_quote_flag = 0;
		return (1);
	}	
	if (check_double_quote(line))
	{
		flag->d_quote_flag = 1;
		return (1);
	}
	else
		return (0);
}

int	meet_quote(t_flags *flag, char *line)
{
	if (flag->quote_flag == 1)
	{
		flag->quote_flag = 0;
		return (1);
	}	
	if (check_quote(line))
	{
		flag->quote_flag = 1;
		return (1);
	}
	else
		return (0);
}

char	*find_next_word(char *space_start)
{
	int	i;

	i = 0;
	while (ft_isspace(space_start[i]))
		i++;
	return (&space_start[i]);
}

char	*make_new_line(char *line, char *current, char *start)
{
	char	*ret;
	char	*before_start;
	int		i;

	i = 0;
	while (&line[i] != current)
		i++;
	before_start = ft_calloc(i + 2, sizeof(char));
	if (before_start == 0)
		error_exit(NULL);
	i = 0;
	while (&line[i] != current)
	{
		before_start[i] = line[i];
		i++;
	}
	before_start[i] = ' ';
	ret = ft_strjoin(before_start, start);
	if (ret == 0)
		error_exit(NULL);
	free(before_start);
	free(line);
	return (ret);
}

char	*first_line_setting(char *line, char **env)
{
	int		i;
	t_flags	flag;
	char	*ret;

	i = 0;
	ret = line;
	flag.d_quote_flag = 0;
	flag.quote_flag = 0;
	while (ret[i])
	{
		if (ret[i] == '\"' && flag.quote_flag == 0)
			if (!meet_double_quote(&flag, &ret[i]))
				error_exit("wrong quote pair!");
		if (ret[i] == '\'' && flag.d_quote_flag == 0)
			if (!meet_quote(&flag, &ret[i]))
				error_exit("wrong quote pair!");
		if (ret[i] == '$' && flag.quote_flag != 1)
			ret = execute_dollar(line, i, env);
		if (ft_isspace(ret[i]) && ft_isspace(ret[i + 1]) && \
		flag.d_quote_flag == 0 && flag.quote_flag == 0)
			ret = make_new_line(ret, &ret[i], find_next_word(&ret[i + 1]));
		i++;
	}
	return (ret);
}
