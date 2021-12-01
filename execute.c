#include "header.h"
/**
 * execute - executes the commands passed to it
 * @commands: input string array of commands
 * Return: 0 on success, -1 on failure
 */
int execute(char **commands)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid != 0)
		wait(&status);
	if (pid == 0)
		execve(commands[0], commands, NULL);
return (0);
}
