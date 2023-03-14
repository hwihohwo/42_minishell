#include <stdio.h>
#include <unistd.h>

typedef struct s_fd
{
	int		fd[2];
	int		fd_read;
	int		fd_write;
	int		pipe_read;
	int		pipe_write; // fd[1]
	int		pipe_cnt;
	int		pipe_idx;
	int		heredoc;
	int		idx;
	int		fd_flag; // infile 이 없어서 fd = open(infile)이 -1 인 경우, 
					// dup2(-1, STDIN)은 bad file descriptor 에러가 발생한다. 기존 bash는 발생하지 않음 
}	t_fd;
/*
void	child_pipe(t_fd *fd_data)
{
	if (fd_data->pipe_idx == 0)
	{	// first
		dup2(fd_data->pipe_write, STDOUT_FILENO);
		close(fd_data->pipe_write);
	}
	else if (fd_data->pipe_idx == fd_data->pipe_cnt - 1)
	{	// last
		close(fd_data->fd[0]);
		
	}
	else
	{	// mid

	}
	// 리다이렉션 타입이 있다면 거기서 읽거나 써줌
	if (fd_data->fd_read != STDIN_FILENO)
		dup2(fd_data->fd_read, STDIN_FILENO);
	if (fd_data->fd_write != STDOUT_FILENO)
		dup2(fd_data->fd_write, STDOUT_FILENO);
}

void	parent_pipe(t_fd *fd_data)
{
	// 파이프가 mid or last라면 pipe_read를 닫아줌
	if (fd_data->pipe_idx > 0)
		close(fd_data->pipe_read);
	if (fd_data->pipe_idx < fd_data->pipe_cnt)
	{	// 파이프가 last가 아니라면 pipe_read에 fd[0] 저장(다음 파이프에 연결하기 위해)
		close(fd_data->fd[1]);
		fd_data->pipe_read = fd_data->fd[0];
	}
}
*/
/*
void	child_pipe(t_fd *fd_data)
{
	if (fd_data->pipe_idx > 0)
	{
		dup2(fd_data->pipe_read, STDIN_FILENO);
		close(fd_data->pipe_read);
	}
	if (fd_data->pipe_idx < fd_data->pipe_cnt)
	{
		close(fd_data->fd[1]); // 안 쓰는 파이프는 닫아야 입력대기에 안 걸림
		dup2(fd_data->pipe_write, STDOUT_FILENO);
		close(fd_data->pipe_write);
	}
}

void	parent_pipe(t_fd *fd_data)
{
	if (fd_data->pipe_idx > 0)
		close(fd_data->pipe_read);
	if (fd_data->pipe_idx < fd_data->pipe_cnt)
	{
		close(fd_data->fd[0]);
		fd_data->pipe_read = fd_data->fd[0];
	}
}
*/

/*

void	syntax_pipe(t_ast **root, t_tokenlist **token_node)
{
	// 파이프 단독으로 들어오거나 끝이 파이프로 끝나는 경우 &(*token_node)->next == NULL 인 경우
	// 시작할 때 체크하지 않으면 (*token_node)->type 을 확인할 때 터짐
//	if (*token_node == NULL)
//		return ;
	if (*root == NULL)
		*root = new_ast_node("P", "PIPE"); // T = tree_node
	if ((*token_node) == NULL)
		return ;
	if ((*token_node)->data->type != PIPE)
		syntax_cmd(&(*root)->left, token_node);
	// syntax_cmd 에서 null 확인후 돌려받았을때 종료
	if (*token_node == NULL)
		return ;
	if ((*token_node)->data->type == PIPE)
		syntax_pipe(&(*root)->right, &(*token_node)->next);
}

void	syntax_cmd(t_ast **node, t_tokenlist **token_node)
{
//	if ((*token_node) == NULL)
//		return ;
	if (*node == NULL)
		*node = new_ast_node("C", "CMD");
	if ((*token_node)->data->type == SCMD)
		syntax_simple_cmd(&(*node)->right, token_node);
	// syntax_simple_cmd 에서 *token_node->next 값이 null인지 확인 
	if (*token_node == NULL)
		return ;
	if ((*token_node)->data->type != CMD && (*token_node)->data->type != PIPE && \
	(*token_node)->data->type != SCMD)
		syntax_redir(&(*node)->left, token_node);
	// CMD 는 REDIR과 달리 복수 개의 명령어 인자가 들어와도 하나로 인식하기 때문에 REDIR처럼 가지치기 할 필요가 없음
}

void	syntax_redir(t_ast **node, t_tokenlist **token_node)
{
//	if ((*token_node) == NULL)
//		return ;
	if (*node == NULL)
		*node = new_ast_node("R", "REDIRS");
	syntax_simple_redir(&(*node)->left, token_node);
	// syntax_simple_redir 에서 *token_node_next 값이 null인지 확인
	if (*token_node == NULL)
		return ;
	if ((*token_node)->data->type == INPUT || (*token_node)->data->type == OUTPUT || \
	(*token_node)->data->type == HEREDOC || (*token_node)->data->type == APPEND)
		syntax_redir(&(*node)->right, token_node);
	else if ((*token_node)->data->type == CMD || (*token_node)->data->type == SCMD)
		syntax_cmd(&(*node)->left, token_node);
}

void	syntax_simple_redir(t_ast **node, t_tokenlist **token_node)
{
	if (*node == NULL)
		redir_split(node, token_node);
	*token_node = (*token_node)->next;
}

void	syntax_simple_cmd(t_ast **node, t_tokenlist **token_node)
{
	if (*node == NULL)
		*node = new_ast_node("S", "SCMD");
	(*node)->left = new_ast_node((*token_node)->data->order, (*token_node)->data->argu);
	*token_node = (*token_node)->next;
}
*/