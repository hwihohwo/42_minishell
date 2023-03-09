/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:59:09 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/13 15:48:06 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*arr1;
	unsigned char	*arr2;

	arr1 = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (arr1[index] > arr2[index])
			return (1);
		else if (arr1[index] < arr2[index])
			return (-1);
		else if (arr1[index] == 0 && arr2[index] == 0)
			return (0);
		index++;
	}
	return (0);
}
