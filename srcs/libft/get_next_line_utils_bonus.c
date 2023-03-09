/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 02:32:24 by seonghwc          #+#    #+#             */
/*   Updated: 2022/10/28 02:32:33 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	read_and_check(int fd, char *buffer, char **static_string)
{
	int		i;
	int		read_val;
	int		first_flag;

	first_flag = 1;
	while (1)
	{
		i = 0;
		while (i < BUFFER_SIZE)
			buffer[i++] = '\0';
		read_val = read(fd, buffer, BUFFER_SIZE);
		if (read_val == -1 || (read_val == 0 && first_flag == 1 && \
		ft_strlen_gnl(*static_string) == 0))
			return (-1);
		*static_string = ft_strjoin_gnl(*static_string, buffer);
		if (*static_string == NULL)
			return (-1);
		i = 0;
		while ((*static_string)[i])
			if ((*static_string)[i++] == '\n')
				return (1);
		if (read_val < BUFFER_SIZE && first_flag != 1)
			return (1);
		first_flag = 0;
	}
}

char	*ft_strjoin_gnl(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*ret;
	char	*temp;

	i = 0;
	j = 0;
	temp = str1;
	ret = (char *)malloc(ft_strlen_gnl(str1) + ft_strlen_gnl(str2) + 1);
	if (ret == NULL)
		return (NULL);
	if (str1 != NULL)
		while (str1[i])
			ret[j++] = str1[i++];
	i = 0;
	if (str2 != NULL)
		while (str2[i])
			ret[j++] = str2[i++];
	ret[j] = '\0';
	if (temp != NULL)
		free(temp);
	return (ret);
}

char	*ft_strdup_gnl(char *str)
{
	int		i;
	int		length;
	char	*ret;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	length = i;
	ret = (char *)malloc(length + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*cut_and_free(char *static_string)
{
	int		i;
	int		j;
	int		length;
	char	*temp;

	i = 0;
	j = 0;
	temp = static_string;
	while (temp[i] != '\n' && temp[i])
		i++;
	if (temp[i] == '\n')
		i++;
	length = ft_strlen_gnl(&temp[i]);
	static_string = (char *)malloc(length + 1);
	if (static_string == NULL)
		return (NULL);
	while (j < length)
		static_string[j++] = temp[i++];
	static_string[j] = '\0';
	free(temp);
	return (static_string);
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
