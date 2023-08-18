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
int print_error(char *command);
int exe_fun(char *path, char **commands, char **envp);

#endif
