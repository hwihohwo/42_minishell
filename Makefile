# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 13:00:06 by seonghwc          #+#    #+#              #
#    Updated: 2023/03/13 14:29:49 by seonghwc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
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
		./srcs/readline/readline.c \
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
		$(EX_DIR)execute_node.c \
		$(EX_DIR)execute_redir.c \
		$(EX_DIR)execute_utils.c \
		$(EX_DIR)execute_functions.c \
		$(EX_DIR)execute_command.c

		
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
# -lreadline : readlinežĚīŽĚľŽäĒ ŽĚľžĚīŽłĆŽü¨Ž¶¨Ž•ľ ŽßĀŪĀ¨
# žĽīŪĆĆžĚľ Í≥ľž†ē 4Žč®Í≥Ą
# ž†Ąž≤ėŽ¶¨Íłį -> žĽīŪĆĆžĚľŽü¨ -> žĖīžÖąŽłĒŽü¨(%.o:%.c) -> ŽßĀžĽ§(NAME: OBJS)