/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:15:05 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/28 15:06:24 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ret;
	size_t			index;

	index = 0;
	ret = (unsigned char *)b;
	while (index < len)
	{
		ret[index] = (unsigned char)c;
		index++;
	}
	return (b);
}
