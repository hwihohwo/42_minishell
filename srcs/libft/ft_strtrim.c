/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:59:36 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/28 21:57:15 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_check(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		j;
	char	*ret;

	if (s1 == NULL)
		return (NULL);
	j = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (set_check(s1[start], set) == 0)
		start++;
	while (set_check(s1[end], set) == 0 && end > start)
		end--;
	if (start > end)
		ret = (char *)malloc(1);
	else
		ret = (char *)malloc(end - start + 2);
	if (ret == NULL)
		return (NULL);
	while (start <= end)
		ret[j++] = s1[start++];
	ret[j] = 0;
	return (ret);
}
