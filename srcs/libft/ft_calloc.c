/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:50:21 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/12 19:36:19 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t		index;
	char		*ret;

	index = 0;
	ret = malloc(count * size);
	if (ret == NULL)
		return (NULL);
	while (index < (count * size))
		ret[index++] = 0;
	return ((void *)ret);
}
