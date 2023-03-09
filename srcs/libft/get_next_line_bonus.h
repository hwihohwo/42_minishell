/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 02:31:53 by seonghwc          #+#    #+#             */
/*   Updated: 2022/11/25 22:42:00 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
int		read_and_check(int fd, char *buffer, char **static_string);
char	*ft_strjoin_gnl(char *str1, char *str2);
int		ft_strlen_gnl(char *str);
char	*ft_strdup_gnl(char *str);
char	*cut_and_free(char *static_string);
void	free_(char *buffer, char *static_string);
#endif