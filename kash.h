#ifndef _KASH_H
#define _KASH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* kash functions */
void prompt(void);
char *kash_read(void);
char **kash_split(char *line);
void kash_exec(char **av, char **env);

/* malloc functions */
char **_realloc(char **ntr, int size);
void _free(char **vector);

/* built-in functions */
void kash_exit(char **av);
void kash_cd(char **av);
void kash_env(char **av);
int kash_builtin(char **av);

/* string functions */
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);

/* helper functions */
char *_getenv(char **env, char *name);
char **pathenv(char **env);

/* built-in commands */
typedef struct builtin
{
	char *command;
	void (*func)(char **av);
}builtin;


#endif
