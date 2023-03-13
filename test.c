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
