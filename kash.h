#ifndef _KASH_H
#define _KASH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void prompt(void);
char *kash_getline(void);
char **kash_splitline(char *line);
void kash_exec(char **av);








#endif
