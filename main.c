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
	char **commands, **thepath = pathfinder();
	char *fullpath = malloc(sizeof(char) * 1024);
	struct stat st;

	if (buffer == NULL)
		return (-1);
	if (isatty(STDIN_FILENO))
		_printf("$ ");
	while ((check = getline(&buffer, &bufsize, stdin)) != -1)
	{
		i++;
		/*if (*buffer == ' ')
		{
			for (x = 0; *buffer == ' '; x++)
				buffer++;
				}*/
		if (_strcmp(buffer, "\n") == 0)
		{}
		else
		{
			buffer[_strlen(buffer) - 1] = '\0', commands = splitter(buffer);
			/*buffer = buffer - x;*/
			if (_strcmp(commands[0], "exit") == 0)
			{
				free(buffer);
				free(fullpath);
				free(thepath);
				free(commands);
				exit(exitstatus);
			}
			else if (_strcmp2(commands[0], "env") == 0)
				printenv();
			else
			{
				if (stat(commands[0], &st) == 0)
				{
					execute(commands[0], commands);
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
						_printf("%s: %d: %s: not found\n", argv[0], i, commands[0]), exitstatus = 127;
					}
				}
			}
			free(buffer);
		}
		if (isatty(STDIN_FILENO))
			_printf("$ ");
		/*free(commands);*/
	}
	if (check == -1)
	{
		if (isatty(STDIN_FILENO))
			_printf("\n");
		free(buffer), free(fullpath), free(thepath), exit(exitstatus);
	}
	return (0);
}
