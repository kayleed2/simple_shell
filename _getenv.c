#include "header.h"
/**
 * _getenv - gets the environment variable indicated
 * @var - input variable you want
 * Return: a string of the envrionment variable
 */
char * _getenv(char *var)
{
	char *envvar = malloc(sizeof(char) * 1024);
	char *envfinal = malloc(sizeof(char) * 1024);
	char *envtok;
	int x;

	for (x = 0; environ[x] != NULL; x++)
	{
		if (_strncmp(var, environ[x], 4) == 0)
		{
			_strcpy(envvar, environ[x]);
			envtok = strtok(envvar, "=");
			envtok = strtok(NULL, "=");
			_strcpy(envfinal, envtok);
		}
		else
		{
			envfinal = '\0';
		}
	}
	return(envfinal);
}
