#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int a, char **args)
{
    char space[] = " ";
    if (!strcmp(args[1], "-v"))
    {
        int out = mkdir(args[2], 0777);
        if (out == 0)
        {
            printf("mkdir: Directory Created Successfully: %s\n", args[2]);
        }
        else if (out < 0)
        {
            printf("mkdir: Cannot Create Directory %s", args[2]);
            printf(": File Exists\n");
        }
    }
    else if (!strcmp(args[1], "simple"))
    {
        int out = mkdir(args[2], 0777);
        if (out < 0)
        {
            printf("mkdir: Cannot Create Directory %s", args[2]);
            printf(": File Exists\n");
        }
    }
    else if (!strcmp(args[1], "simple2"))
    {
        int out = mkdir(args[2], 0777);
        if (out < 0)
        {
            printf("mkdir: Cannot Create Directory %s", args[2]);
            printf(": File Exists\n");
        }
        int res = chdir(args[2]);
        if (res < 0)
        {
            printf("Directory cannot be changed\n");
        }
    }
    return 0;
}