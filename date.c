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
    time_t time_now;
    time(&time_now);
    if (!strcmp(args[1], "-u"))
    {
        printf("UTC ");
        struct tm *time3;
        time3 = gmtime(&time_now);
        char string[100];
        strftime(string, 100, "%a %b %d %H:%M:%S %Y", time3);
        printf("%s\n", string);
    }
    else if (!strcmp(args[1], "-R"))
    {
        printf("IST");
        printf(" +0530 ");
        printf("%s", ctime(&time_now));
    }
    else if (!strcmp(args[1], "simple"))

    {
        printf("IST ");
        printf("%s", ctime(&time_now));
    }
    return 0;
}