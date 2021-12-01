#include "header.h"
/**
 * main - Simple shell
 * Return: 0 on success
 */
int main(void)
{
	size_t bufsize = 1024;
	pid_t pid;
	char *buffer = malloc(bufsize * sizeof(char));
	int status, x;
	char **commands;
	char **thepath = pathfinder();
	char *fullpath = malloc(sizeof(char) * 1024);
	struct stat st;

	if (buffer == NULL)
		return (-1);
	_printf("$ ");
	while (getline(&buffer, &bufsize, stdin) != -1)
	{
		if (_strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			free(fullpath);
			free(thepath);
			free(commands);
			exit(0);
		}
		if (_strcmp(buffer, "env\n") == 0)
				printenv();
		buffer[_strlen(buffer) - 1] = '\0';
		commands = splitter(buffer);
		if (stat(commands[0], &st) == 0)
		{
			pid = fork();
			if (pid != 0)
				wait(&status);
			if (pid == 0)
				execve(commands[0], commands, NULL);
		}
		else
		{
			for (x = 0; thepath[x] != NULL; x++)
			{
				_strcpy(fullpath, thepath[x]);
				_strcat(fullpath, "/");
				_strcat(fullpath, commands[0]);
				if (stat(fullpath, &st) == 0)
				{
					pid = fork();
					break;
				}
			}
		}
		if (pid != 0)
			wait(&status);
		if (pid == 0)
			execve(fullpath, commands, NULL);
		_printf("$ ");
	}
	return (0);
}
