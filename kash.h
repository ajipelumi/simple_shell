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
void kash_exec(char **av);

/* malloc functions */
char **_realloc(char **ntr, int size);


/* built-in commands */
typedef struct builtin
{
	char *command;
	void (*func)(char **av);
}builtin;


#endif
