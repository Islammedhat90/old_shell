#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

extern char *shell_name;
extern char **environ;

int free_arr(char **arr);
char **com_arr(char *line, char *delim);
char *_getenv(char *var);
char *handle_line(char *line);
char *get_path(char *command);
void handle_path(char **commands);
int print_error(char *command);
int exe_fun(char *path, char **commands, char **envp);

int builtin_checker(char *command);
int handle_builtin(int m);
void my_exit(char *command);

char* appendStr(char* restrict  destination, char* restrict source);
char *copyStr(char* restrict  destination, char* restrict source);
size_t lengthOfStr(const char * string);

#endif
