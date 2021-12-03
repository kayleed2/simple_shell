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
#include <stdarg.h>
#include <limits.h>

/**
 * struct function - structure to find the correct function for a specifier
 * @spec: The specifier in question
 * @funct: The function associated with the specifier
 */
typedef struct function
{
	char *spec;
	int (*funct)(va_list *);
} function_t;

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char **splitter(char *str);
extern char **environ;
char **pathfinder(void);
void printenv(void);
char *_getenv(char *var);
int _strncmp(char *s1, char *s2, size_t n);
int _putchar(char c);
int _printf(const char *format, ...);
int _spec_c(va_list *args);
int _spec_s(va_list *args);
int _spec_di(va_list *args);
int _spec_pct(va_list *args);
int _spec_b(va_list *args);
int (*_get_function(char s))(va_list *args);
void reverse(char str[], int length);
char *_itoa(int n, char *str, int base);
int _spec_r(va_list *args);
int _spec_R(va_list *args);
char *_chardup(char chr);
int execute(char *path, char **commands);
int freedom(char *a, char *b, char **c, char **d);
char *buildthepath(char *fullpath, char *material1, char *material2);
int _strcmp2(char *s1, char *s2);

#endif
