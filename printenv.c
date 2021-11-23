#include <unistd.h>
#include <stdio.h>
/**
 * main - Prints env
 * Return: 0 on success, -1 on failure
 */

int main(void)
{
	int i = 0;

	while (environ[i])
		printf("%s\n", environ[i++]);

	return (0);
}
