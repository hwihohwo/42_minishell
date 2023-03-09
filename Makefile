# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 13:00:06 by seonghwc          #+#    #+#              #
#    Updated: 2023/03/09 16:02:21 by seonghwc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
NAME = minishell
LINKING_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
COMPILE_FLAGS = -I${HOME}/.brew/opt/readline/include
LIBFT = -L ./srcs/libft/ -lft
RM = rm
RMFLAGS = -f
P_DIR = ./srcs/parse
TK_DIR = ./srcs/token/
EX_DIR = ./srcs/execute/
SRCS = 	main.c \
	   	$(TK_DIR)tokenize.c \
	   	$(TK_DIR)data_free.c \
	   	$(TK_DIR)token_utils.c \
	   	$(TK_DIR)token_linked_list.c \
	   	$(TK_DIR)first_line_setting.c  \
		$(P_DIR)/parse.c \
		$(P_DIR)/lexer.c \
		$(P_DIR)/lexer_node.c \
		$(P_DIR)/lexer_utils.c \
		$(EX_DIR)execute.c \
		$(EX_DIR)execute_utils.c \
		$(EX_DIR)execute_each_type.c
		
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	@$(MAKE) -C ./srcs/libft/
	$(CC) $(CFLAGS) $(LINKING_FLAGS) $(OBJS) -o $(NAME) $(LIBFT) -I ./includes/
%.o: %.c
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) -c $^ -o $@
clean:
	@$(MAKE) -C ./srcs/libft/ clean
	$(RM) $(RMFLAGS) $(OBJS)
fclean: clean
	@$(MAKE) -C ./srcs/libft/ fclean
	$(RM) $(RMFLAGS) $(NAME)
re : fclean all
# -lreadline : readline이라는 라이브러리를 링크
# 컴파일 과정 4단계
# 전처리기 -> 컴파일러 -> 어셈블러(%.o:%.c) -> 링커(NAME: OBJS)