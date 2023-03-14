/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_token_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:41:16 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/14 18:43:53 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*input_string(char *line, int *i, int sav)
{
	int		j;
	char	*ret;

	j = 0;
	ret = ft_calloc(*i - sav + 1, sizeof(char));
	if (ret == 0)
		error_exit(0);
	while (sav < *i)
		ret[j++] = line[sav++];
	return (ret);
}

void	skip_redir(char *line, int *i)
{
	if (line[*i] == '<' || line[*i] == '>')
		while ((line[*i] == '<' || line[*i] == '>') && line[*i])
			(*i)++;
	while (ft_isspace(line[*i]))
		(*i)++;
	while (!ft_isspecial(line[*i]) && line[*i] && !ft_isspace(line[*i]))
		(*i)++;
}

int	count_no_dir(char *line, int i, int sav)
{
	int	count;

	count = 0;
	while (sav < i)
	{
		if (line[sav] == '<' || line[sav] == '>')
		{
			skip_redir(&line[sav], &sav);
			continue ;
		}
		count++;
		sav++;
	}
	return (count);
}

char	*input_string_no_redir(char *line, int *i, int sav)
{
	int		j;
	int		count;
	char	*ret;

	j = 0;
	count = count_no_dir(line, *i, sav);
	ret = ft_calloc(count + 1, sizeof(char));
	if (ret == 0)
		error_exit(0);
	while (sav < *i)
	{
		if (line[sav] == '<' || line[sav] == '>')
		{
			skip_redir(&line[sav], &sav);
			if (ret[j - 1] != ' ')
				ret[j++] = ' ';
			continue ;
		}
		ret[j++] = line[sav++];
	}
	return (ret);
}
