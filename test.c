#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **env)
{
	int	i = 0;

	while (env[i])
	{
		printf("%d : %s\n", i, env[i]);
		free(env[i]);
		i++;
	}
}