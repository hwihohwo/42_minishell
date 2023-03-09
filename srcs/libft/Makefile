# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 19:35:10 by seonghwc          #+#    #+#              #
#    Updated: 2023/03/04 16:26:58 by seonghwc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME                    = libft.a
CC						= cc
SRCS                    = ft_atoi.c \
                      ft_bzero.c \
                      ft_calloc.c \
                      ft_isalnum.c \
                      ft_itoa.c \
                      ft_isalpha.c \
                      ft_isascii.c \
                      ft_isdigit.c \
                      ft_isprint.c \
                      ft_memchr.c \
                      ft_memcmp.c \
                      ft_memcpy.c \
                      ft_memmove.c \
                      ft_memset.c \
                      ft_split.c \
                      ft_strchr.c \
                      ft_strdup.c \
                      ft_striteri.c \
                      ft_strlcat.c \
                      ft_strlcpy.c \
                      ft_strlen.c \
                      ft_strncmp.c \
                      ft_strnstr.c \
                      ft_strrchr.c \
                      ft_strjoin.c \
                      ft_strtrim.c \
                      ft_strmapi.c \
                      ft_substr.c \
                      ft_tolower.c \
                      ft_toupper.c \
                      ft_putchar_fd.c \
                      ft_putstr_fd.c \
                      ft_putendl_fd.c \
                      ft_putnbr_fd.c \
					  ft_printf_utils.c \
					  ft_printf.c \
					  specifier_cases_1.c \
					  specifier_cases_2.c \
					  get_next_line_bonus.c \
					  get_next_line_utils_bonus.c \
					ft_lstsize.c \
                    ft_lstadd_front.c \
                    ft_lstclear.c \
                    ft_lstdelone.c \
                    ft_lstiter.c \
                    ft_lstlast.c \
                    ft_lstmap.c \
                    ft_lstadd_back.c \
                    ft_lstnew.c
OBJS                    = $(SRCS:%.c=%.o)
FLAGS                   = -Wall -Wextra -Werror

$(NAME)     :   $(OBJS)
	ar rc $@ $^
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -D BUFFER_SIZE=100000 -I .
all :   $(NAME)
clean   :
	rm -f $(OBJS)
fclean  :   clean
	rm -f $(NAME)
re  :   fclean all
.PHONY  :   all clean fclean re