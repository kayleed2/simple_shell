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
	size_t n;
	int status, i;
	char **commands;
	struct stat st;

	if (buffer == NULL)
		return (-1);
	printf("$ ");
	while (getline(&buffer, &bufsize, stdin) != -1)
	{
		if (_strcmp(buffer, "exit\n") == 0)
		{
			while (commands[i])
			{
				free(commands[i]);
				i++;
			}
			free(commands);
			exit(0);
		}
		buffer[_strlen(buffer) - 1] = '\0';
		commands = splitter(buffer);
		if (stat(commands[0], &st) == 0)
			pid = fork();
		else
			printf("%s not found\n", commands[0]);
		if (pid != 0)
			wait(&status);
		if (pid == 0)
		{
			execve(commands[0], commands, NULL);
		}
		printf("$ ");
	}
free(buffer);
return (0);
}
