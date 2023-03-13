/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:24:43 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/09 16:01:30 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	terminal_setting(void)
{
	struct termios	new_term;

	tcgetattr(STDIN_FILENO, &new_term);
	new_term.c_lflag = ~(ECHOCTL);
	new_term.c_cc[VMIN] = 1;
	new_term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
}

void	sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signal_setting(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	input_ctrl_d(void)
{
	ft_printf("\033[1A");
	ft_printf("\033[12C");
	ft_printf("exit\n");
}

int	ft_readline(char **envp)
{
	char			*line;
	struct termios	old_term;
	t_ast			*ast;
	t_tokenlist		*token_list;

	first_setting(&old_term);
	while (1)
	{
		line = readline("minishell $ ");
		if (!line)
		{
			input_ctrl_d();
			break ;
		}
		else
		{
			add_history(line);
			token_list = tokenize(line);
			ast = syntax_analyzer(token_list);
			print_tree(&ast); // execute로 수정?
			execute(ast, envp);
		}
		tk_lstclear(&token_list, token_data_free);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	if (ac != 1)
		return (0);

	av = NULL;
	return (ft_readline(envp));
}