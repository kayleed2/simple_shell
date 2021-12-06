#include "header.h"
/**
 * execute - executes the commands passed to it
 * @path: Path to check
 * @commands: input string array of commands
 * Return: 0 on success, -1 on failure
 */
int execute(char *path, char **commands)
{
	pid_t pid;
	int status, exitstatus;

	pid = fork();
	if (pid != 0)
		wait(&status);
	if (pid == 0)
		execve(path, commands, environ);
	if (WIFEXITED(status))
		exitstatus = WEXITSTATUS(status);
	return (exitstatus);
}
