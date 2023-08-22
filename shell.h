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
char *print_number(int count);
void print_commanderr(char *command, int count);
int exe_fun(char *path, char **commands, char **envp);


int builtin_checker(char *command);
int handle_builtin(int m);
void my_exit(char *command);
void my_env(void);

char *appendStr(char *destination, char source);
char *copyStr(char *destination, char *source);
size_t lengthOfStr(const char * string);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
int compStr(const char *string1, const char *string2);

#endif
