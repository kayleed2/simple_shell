#include "header.h"
/**
 * freedom - frees stuff that needs to be freed
 * @a: first thing to be freed
 * @b: second thing to be freed
 * @c: third thing to be freed
 * @d: fourth thing to be freed
 */
int freedom(char *a, char *b, char **c, char **d)
{
	if (a != NULL)
		free(a);
	if (b != NULL)
		free(b);
	if (c != NULL)
		free(c);
	if (d != NULL)
		free(d);

	return (0);
}
