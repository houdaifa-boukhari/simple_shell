#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;
void *ft_getline();
char    **ft_split(char *str);
size_t	ft_strlen(const char *str);
void	free_arrays(char **str);
int ft_execute(char **cmds, char **argv, int idx);
size_t  ft_strlen(const char *str);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strdup(const char *src);
int     ft_strcmp(char *s1, char *s2);
char    *ft_strcat(char *dest, char *src);
char    *ft_itoa(int n);
char *ft_getenv(char *var_env);
char *ft_getpath(char *cmd);
void displaye_error(char *name, char *cmd, int index);
int built_in(char *cmd);
void handle_cmd(char **cmd, int *status);
void displaye_env(char **cmd, int *status);
void ft_exit(char **cmd, int *status);

#endif
