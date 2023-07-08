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
    DIR *dir = opendir(".");
    struct dirent *de;
    while ((de = readdir(dir)) != NULL)
    {
        if (!strcmp(args[1], "-1"))
        {
            printf("%s\n", de->d_name);
        }
        else if (!strcmp(args[1], "-A"))
        {
            if (!strcmp(de->d_name, "."))
            {
                continue;
            }
            if (!strcmp(de->d_name, ".."))
            {
                continue;
            }
            printf("%s\t", de->d_name);
        }
        else if (!strcmp(args[1], "simple"))
        {
            printf("%s\t", de->d_name);
        }
    }
    closedir(dir);
}