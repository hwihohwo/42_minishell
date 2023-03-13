/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:34:31 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/11 21:55:29 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_newline_flag(char *argu, int *n_flag, int *i)
{
	int	start;

	start = *i;
	if (ft_strncmp(&argu[*i], "-n", 2) == 0)
	{
		(*i) += 2;
		while (argu[*i] == 'n' && !ft_isspace(argu[*i]) && argu[*i])
			(*i)++;
		if (ft_isspace(argu[*i]) || !argu[*i])
			*n_flag = 1;
		else
			*i = start;
	}
	if (ft_isspace(argu[*i]))
		(*i)++;
}

void	cursur_move(char *argu, int *i, int *n_flag)
{
	while (argu[*i] == 'e' || argu[*i] == 'c' || argu[*i] == 'h' || \
	argu[*i] == 'o')
		(*i)++;
	while (ft_isspace(argu[*i]))
		(*i)++;
	if (argu[*i] == '-')
		check_newline_flag(argu, n_flag, i);
}

void	flag_controll_echo(t_flags *flag, int state)
{
	if (state == 1)
	{
		if (flag->d_quote_flag == 0)
			flag->d_quote_flag = 1;
		else
			flag->d_quote_flag = 0;
	}
	else
	{
		if (flag->quote_flag == 0)
			flag->quote_flag = 1;
		else
			flag->quote_flag = 0;
	}
}

void	quote_echo(char *str, int *i, t_flags *flag)
{
	if (str[*i] == '\"' && flag->quote_flag == 0)
	{
		flag_controll_echo(flag, 1);
		(*i)++;
	}
	else if (str[*i] == '\'' && flag->d_quote_flag == 0)
	{
		flag_controll_echo(flag, 2);
		(*i)++;
	}
}

int	ft_echo(t_tokendata *tokendata)
{
	t_flags	flag;
	int		i;
	int		n_flag;

	i = 0;
	n_flag = 0;
	flag.quote_flag = 0;
	flag.d_quote_flag = 0;
	if (ft_strncmp(tokendata->order, "echo", ft_strlen("echo") + 1) != 0)
		return (-1);
	cursur_move(tokendata->argu, &i, &n_flag);
	while (tokendata->argu[i])
	{
		if (tokendata->argu[i] == '\'' || tokendata->argu[i] == '\"')
			quote_echo(tokendata->argu, &i, &flag);
		if (tokendata->argu[i])
			ft_printf("%c", tokendata->argu[i++]);
	}
	if (n_flag)
		return (1);
	else
		return (ft_printf("\n"));
}
