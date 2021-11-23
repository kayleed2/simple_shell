#include "header.h"
int main(int ac, char *argv[])
{
	int bytes = 1024;
	int status;
	char *cwdpath;
	char *copypath;
	int i = 1, x;
	struct stat fileinfo;

	if (ac != 2)
	{
		printf("Not enough arguments\n");
		return (-1);
	}
	cwdpath = malloc(sizeof(char) * bytes);
	if (!cwdpath)
		return (-1);
	getcwd(cwdpath, bytes);
	copypath = strdup(cwdpath);
	for (x = 0; copypath[x] != '\0'; x++);
	copypath[x] = '/';
	copypath = strcat(copypath, argv[1]);
	status = stat(copypath, &fileinfo);
	printf("%s\n", copypath);
	if (status == 0)
	{
		printf("FILE FINALLY FOUND\n");
		return (0);
	}
	if (status == -1)
	{
		printf("File not found\n");
		return (-1);
	}
	return (0);
}
