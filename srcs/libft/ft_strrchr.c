/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:59:24 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/13 15:44:24 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	int		index;

	len = 0;
	while (s[len])
		len++;
	index = len;
	while (index >= 0)
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index--;
	}
	return (NULL);
}
