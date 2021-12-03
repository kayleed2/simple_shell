#include "header.h"
/**                                                                                                                                                                                                     
* main - Simple shell                                                                                                                                                                                  
* Return: 0 on success 
*/
int main(void)
{
size_t bufsize = 1024;
char *buffer = malloc(bufsize * sizeof(char));
int x, i = 0;
char **commands, **thepath = pathfinder();
char *fullpath = malloc(sizeof(char) * 1024);
struct stat st;

if (buffer == NULL)
  return (-1);
if (isatty(0))
  _printf("($) ");
while (getline(&buffer, &bufsize, stdin) != -1)
{
  i++;
  buffer[_strlen(buffer) - 1] = '\0', commands = splitter(buffer);
  if (_strcmp(buffer, "exit\n") == 0)
              break;
if (_strcmp(buffer, "env\n") == 0)
printenv();
if (stat(commands[0], &st) == 0)
execute(commands[0], commands);
else
{
for (x = 0; thepath[x] != NULL; x++)
{
_strcpy(fullpath, thepath[x]), _strcat(fullpath, "/");
_strcat(fullpath, commands[0]);
if (stat(fullpath, &st) == 0)
{
execute(fullpath, commands);
free(commands);
break;
}
}
if (thepath[x] == NULL)
{
_printf("./hsh: %d: %s: not found\n", i, commands[0]);
if (isatty(0))
free(commands);
}
}
if (isatty(0))
_printf("($) ");
}
free(buffer), free(fullpath), free(thepath), free(commands);
return (0);
 54 }
