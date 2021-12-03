#include "header.h"
/**
 * main - Simple shell
 * Return: 0 on success
 */
int main(void)
{
	size_t bufsize = 1024;
	char *buffer = malloc(sizeof(char) * 1024);
	int x, i = 1;
	char **commands, **thepath;
	char *fullpath = malloc(sizeof(char) * 1024);
	struct stat st;

	if ((buffer == NULL) || (fullpath == NULL))
	{
		free(buffer), free(fullpath), exit (-1);
	}
	if (isatty(0))
		_printf("($) ");
	while (getline(&buffer, &bufsize, stdin) != -1)
	{
		thepath = pathfinder();
		if (_strcmp(buffer, "exit\n") == 0)
		{
			free(buffer), free(fullpath), free(thepath), exit (0);
		}
		else if (_strcmp(buffer, "env\n") == 0)
			printenv();
		else if (_strcmp(buffer, "\n") == 0)
		{
		}
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			commands = splitter(buffer);
			if (stat(commands[0], &st) == 0)
				execute(commands[0], commands);
			else
			{
				for (x = 0; thepath[x] != NULL; x++)
				{
					fullpath = buildthepath(fullpath, thepath[x], commands[0]);
					if (stat(fullpath, &st) == 0)
					{
						execute(fullpath, commands), free(commands);
						free(thepath);
						break;
					}
					else if ((thepath[x + 1]) == NULL)
					{
						_printf("./hsh: %d: %s: not found\n", i, commands[0]);
						free(commands), free(thepath), i++;
					}
				}
			}
		}
		if (isatty(0))
		{
			_printf("($) ");
		}
	}
	free(fullpath),	free(buffer), free(thepath);
	return (0);
}
