/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:56:34 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/28 14:35:41 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	string_num(char const *s, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			num++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (num);
}

static char	*make_string(char *dst, char const *src, int len)
{
	int	i;

	i = 0;
	dst = (char *)malloc(len * sizeof(char) + 1);
	if (dst == NULL)
		return (NULL);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	**make_ret(char **ret, char const *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = 0;
	k = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c)
			i++;
		j = i;
		if (s[i] == '\0')
			break ;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			len++;
		}
		ret[k] = make_string(ret[k], &s[j], len);
		if (ret[k++] == NULL)
			return (NULL);
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**ret;

	if (s == NULL)
		return (NULL);
	j = string_num(s, c);
	ret = (char **)malloc((j + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	ret[j] = 0;
	ret = make_ret(ret, s, c);
	if (ret == NULL)
	{
		j = 0;
		while (ret[j])
			free(ret[j++]);
		free(ret);
		return (NULL);
	}
	return (ret);
}
