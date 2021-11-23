#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct path_list
{
	char *path;
	struct path_list *next;
} path_list;

char *_getenv(const char *name);
path_list *create_path_list();
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char **splitter(char *str);
extern char **environ;

#endif
