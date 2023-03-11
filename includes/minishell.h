/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:08:30 by jeongmil          #+#    #+#             */
/*   Updated: 2023/03/11 20:21:40 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include "../srcs/libft/libft.h"
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>

typedef enum e_token_type
{
	CMD,
	INPUT,
	OUTPUT,
	HEREDOC,
	APPEND,
	PIPE,
	TREE
}	t_token_type;

typedef struct s_ast
{
	enum e_token_type	type;
	char				*order;
	char				*argu;
	struct s_ast		*left;
	struct s_ast		*right;
}						t_ast;

typedef struct s_tokendata
{
	enum e_token_type	type;
	char				*order;
	char				*argu;
}	t_tokendata;

typedef struct s_tokenlist
{
	t_tokendata			*data;
	struct s_tokenlist	*next;
}	t_tokenlist;

typedef struct s_flags
{
	int	d_quote_flag;
	int	quote_flag;
}	t_flags;

// readline
void			readline_start(char **env);
void			signal_setting(void);
void			sigint_handler(int signal);
void			terminal_setting(void);
void			input_ctrl_d(void);

// token
t_tokenlist		*tokenize(char *line, char **env);
char			*input_string(char *line, int *i, int sav);
t_tokendata		*new_tokendata(char	*line, int *i);
t_tokendata		*tkdata_2(char *line, int *i, int sav, t_tokendata *token_data);

void			token_data_free(t_tokendata *token_data);
void			error_exit(void);

int				ft_isspace(char c);
int				ft_isspecial(char c);
int				check_double_quote(char *str);
int				check_quote(char *str);
void			first_setting(struct termios *old_term);

void			tk_lstadd_back(t_tokenlist **lst, t_tokenlist *new);
t_tokenlist		*tk_lstnew(t_tokendata *content);
void			tk_lstclear(t_tokenlist **lst, void (*del)(t_tokendata *));
void			tk_lstiter(t_tokenlist *lst, void (*f)(t_tokendata *));

int				meet_double_quote(t_flags *flag, char *line);
int				meet_quote(t_flags *flag, char *line);
char			*find_next_word(char *space_start);
char			*make_new_line(char *line, char *current, char *start);
char			*first_line_setting(char *line, char **env);

//execute_dollar
int				dollar_length_count(char *line, int i);
char			*extract_env(char *env);
char			*make_to_one_string(char *before_start, char *env_value, \
char *after_end);
char			*replace_dollar(char *line, char *env_value, \
int start, int end);
char			*execute_dollar(char *line, int *i, char **env);

//ft_echo
void			check_newline_flag(char *argu, int *n_flag, int *i);
void			cursur_move(char *argu, int *i, int *n_flag);
void			flag_controll_echo(t_flags *flag, int state);
void			quote_echo(char *str, int *i, t_flags *flag);
int				ft_echo(t_tokendata *tokendata);

// parse.c
t_ast			*syntax_analyzer(t_tokenlist *token_node);
t_ast			*token_parse(char **argv);

// lexer.c
void			syntax_pipe(t_ast **root, t_tokenlist **token_node);
void			syntax_cmd(t_ast **node, t_tokenlist **token_node);
void			syntax_redir(t_ast **node, t_tokenlist **token_node);
void			syntax_simple_redir(t_ast **node, t_tokenlist **token_node);
void			syntax_simple_cmd(t_ast **node, t_tokenlist **token_node);

// lerxer_node.c
t_ast			*new_ast_node(char *order, char *argv);

// lexer_utils.c
void			print_tree(t_ast **root);
t_token_type	find_data_type(char *argv);
void			ft_free_sp(char **str);
void			redir_split(t_ast **node, t_tokenlist **token_node);

#endif
