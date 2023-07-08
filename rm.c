#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main(int a, char **args)
{
    if (!strcmp(args[1], "-v"))
    {
        int out = remove(args[2]);
        if(out >= 0)
        {
            printf("The file has been deleted\n");
        }
        else
        {
            printf("The file has not been deleted\n");
        }
    }
    else if (!strcmp(args[1], "-r"))
    {
        int out  = rmdir(args[2]);
        if(out < 0)
        {
            printf("rm: cannot remove the directory:  %s\n",args[2]);
        }
    }
    else if (!strcmp(args[1], "simple"))
    {
        DIR *output  = opendir(args[2]);
        if(output != NULL)
        {
            printf("Cannot remove the directory: %s\n",args[2]);
            return 0;
        }
        int out = remove(args[2]);
        if(out < 0)
        {
            printf("rm: cannot remove the file: %s\n",args[2]);
        }
    }
}