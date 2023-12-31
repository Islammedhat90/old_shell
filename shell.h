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
void fill_array(char **commands, char *copy, char *delim);
char *_getenv(char *var);
char *handle_line(char *line);
int line_checker(char *line);
char *get_path(char *command);
void handle_path(char **commands, int count);
int print_error(char *command, int count);
char *print_number(int count);
void print_commanderr(char *command, int count);
int exe_fun(char *path, char **commands, char **envp);
int delimcheck(char c, const char *delim);
char *_strtok(char *line, const char *delim);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int command_count(char **commands);

int builtin_checker(char *command);
int handle_builtin(int m, char **commands, int count);
void my_exit(char **commands, int count);
void my_env(void);
int _setenv(char *var, char *value);
int my_setenv(char **commands);
int my_cd(char **commands);
void handle_ctrlc(int signum);
int operatorcheck(char *line, int count);
int handle_operator(char *line, int count);
int _isdigit(char *number);
int my_atoi(char *str);

char *appendStr(char *destination, char *source);
char *copyStr(char *destination, char *source);
size_t lengthOfStr(const char *string);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
int compStr(const char *string1, const char *string2);
char *duplStr(char *source);

#endif
