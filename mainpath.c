#include "header.h"
/**
 * main - creates linked list but does not free
 *
 *
 *
 */

/*MAY OR MAY NOT USE SIMILAR CODE - Trentons*/
int main(void)
{
	path_list *head = NULL;
	path_list *tmp;

	head = create_path_list();
	for (tmp = head; tmp != NULL; tmp = tmp->next)
	{
		printf("%s", tmp->path);
		if (tmp->next == NULL)
			break;
		printf(":");
		printf("\n");
	}
	printf("\n");
	return (0);
}
