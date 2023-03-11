#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **env)
{
	char	*str[] = {"a.out", NULL};
	
	if(execve("./a.out", str, env) == -1)
		printf("fail!\n");
}