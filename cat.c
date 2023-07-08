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
    FILE *file_ptr;
    char ch;
    if (!strcmp(args[1], "-T")) // replace tab with ^T
    {
        file_ptr = fopen(args[2], "r");
        if (file_ptr == NULL)
        {
            printf("The File can't be opened\n");
            return 0;
        }
        char str[150];
        char c = fgetc(file_ptr);
        while (c != EOF)
        {
            if (c == '\t')
            {
                printf("^I ");
            }
            else
            {
                printf("%c", c);
            }
            c = fgetc(file_ptr);
        }
        // printf("\n");
        fclose(file_ptr);
        return 0;
    }
    else if (!strcmp(args[1], "-E"))
    {
        file_ptr = fopen(args[2], "r");
        if (file_ptr == NULL)
        {
            printf("The File can't be opened\n");
            return 0;
        }
        char str[150];
        char c = fgetc(file_ptr);
        while (c != EOF)
        {
            printf("%c", c);

            c = fgetc(file_ptr);
            if (c == '\n')
            {
                printf("%c", '$');
            }
        }
        // printf("\n");

        fclose(file_ptr);
    }
    else if (!strcmp(args[1], "simple"))

    {
        file_ptr = fopen(args[2], "r");
        if (file_ptr == NULL)
        {
            printf("The File can't be opened\n");
            return 0;
        }
        while (ch != EOF)
        {
            ch = fgetc(file_ptr);
            printf("%c", ch);
        }
        // printf("\n");
        fclose(file_ptr);
    }
}