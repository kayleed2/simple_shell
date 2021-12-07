#include "header.h"
/**
* error - prints the appropriate error message to the stderr
* @shellname: the name of the shell
* @command: the command entered
* @errornum: the number code of the error
* @comcount: the current count of entered commands
* Return - void
*/
void error(char *shellname, char *command, int errornum, int comcount)
{
	char *comnum = malloc(sizeof(char) * 1024);
	int comint = comcount;

	_itoa(comint, comnum, 10);
	write(STDERR_FILENO, shellname, _strlen(shellname));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, comnum, _strlen(comnum));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	free(comnum);

	if (errornum == 1)
		write(STDERR_FILENO, ": not found\n", 12);
	/*if (errornum == 2)
		write(STDERR_FILENO, ": command not found\n", 20);
	if (errornum == 3)
	write(STDERR_FILENO, ": Permission denied\n", 20);*/
return;
}
