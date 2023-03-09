/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:52:25 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/12 20:54:07 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t count)
{
	unsigned char	*arr1;
	unsigned char	*arr2;
	size_t			index;

	index = 0;
	arr1 = (unsigned char *)ptr1;
	arr2 = (unsigned char *)ptr2;
	while (index < count)
	{
		if (arr1[index] != arr2[index])
			return (arr1[index] - arr2[index]);
		index++;
	}
	return (0);
}
