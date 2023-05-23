#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include <stddef.h>

int  _strlen(const char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *s);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
void printEnvironment();
#endif
