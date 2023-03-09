/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 02:31:37 by seonghwc          #+#    #+#             */
/*   Updated: 2022/11/25 22:42:27 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_all(char *buffer, char **static_string)
{
	free(buffer);
	if (*static_string != NULL)
		free(*static_string);
	*static_string = NULL;
}

char	*get_next_line(int fd)
{
	static char	*static_string[OPEN_MAX];
	char		*buffer;
	char		*temp;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	if (read_and_check(fd, buffer, &static_string[fd]) == -1)
	{
		free_all(buffer, &static_string[fd]);
		return (NULL);
	}
	temp = ft_strdup_gnl(static_string[fd]);
	if (temp == NULL)
	{
		free_all(buffer, &static_string[fd]);
		return (NULL);
	}
	static_string[fd] = cut_and_free(static_string[fd]);
	free (buffer);
	return (temp);
}
