//
// Created by Aletha Yellin on 13/12/2019.
//

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void        go_and_exec(const char *base_path, const char *prefix);

int        ft_str_ends(const char *str, const char *prefix)
{
    char    *ptr;

    ptr = strstr(str, prefix);
    return (ptr && strcmp(ptr, prefix) == 0);
}

#define MU_CMD_BUF_SIZE 1024

void    execute_file(const char *file_name, const char *prefix)
{
    char            command[MU_CMD_BUF_SIZE];

    bzero(command, MU_CMD_BUF_SIZE);
    if(ft_str_ends(file_name, prefix))
    {
            sprintf(command, "./%s", file_name);
            system(command);
            bzero(command, MU_CMD_BUF_SIZE);
    }
}

void        go_and_exec(const char *base_path, const char *prefix)
{
    struct dirent   *dp;
    DIR *dir  = opendir(base_path);
    char            path[1000];

    if (!dir)
        return;
    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            execute_file(dp->d_name, prefix);
            strcpy(path, base_path);
            strcat(path, "/");
            strcat(path, dp->d_name);
            go_and_exec(path, prefix);
        }
    }
    closedir(dir);
}
