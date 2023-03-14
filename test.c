#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int	main(int argc, char **argv, char **env)
{
	char *buffer;

	buffer = 0;
	buffer = getcwd(buffer, 1000);
	printf("%s\n", buffer);
	free(buffer);
}
