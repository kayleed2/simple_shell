#include "header.h"
/**
* main - Simple shell
* @ac: Arg count
* @argv: Arguments
* Return: 0 on success
*/
int main(__attribute__((unused)) int ac, char *argv[])
{
	size_t bufsize = 1024;
	char *buffer = malloc(bufsize * sizeof(char));
	int x, check, exitstatus = 0, i = 0;
	char **commands = NULL, **thepath = pathfinder();
	char *fullpath = malloc(sizeof(char) * 1024);
	struct stat st;

	if (buffer == NULL)
		return (-1);
	if (isatty(STDIN_FILENO))
		_printf("$ ");
	while ((check = getline(&buffer, &bufsize, stdin)) != -1)
	{
		i++;
		if (_strcmp(buffer, "\n") == 0)
		{}
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			commands = splitter(buffer);
			if (_strcmp(commands[0], "exit") == 0)
			{
				break;
			}
			else if (_strcmp(commands[0], "env") == 0)
				printenv();
			else
			{
				if (stat(commands[0], &st) == 0)
				{
					exitstatus = execute(commands[0], commands);
					free(commands);
					continue;
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
							exitstatus = execute(fullpath, commands);
							break;
						}
						else if (thepath[x + 1] == NULL)
							error(argv[0], commands[0], 1, i), exitstatus = 127;
					}
				}
			}
			free(commands);
		}
		if (isatty(STDIN_FILENO))
			_printf("$ ");
	}
		if (isatty(STDIN_FILENO))
			_printf("\n");
		free(buffer);
		free(fullpath);
		if (thepath && thepath[0])
		{
			free(thepath[0]);
			free(thepath);
		}
		if (check != -1)
			free(commands);
		exit(exitstatus);
	return (0);
}
