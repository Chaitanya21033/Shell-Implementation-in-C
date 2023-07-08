#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

char *current_dir;
char *make_dir;
char *date_dir;
char *ls_dir;
char *rm_dir;
char *cat_dir;
char *initial_dir;
int initial_size;
int position = 0;

void *helper_function(void *argument)
{
    system(argument);
    return NULL;
}

void two_para_func(char *dir, char *input1, char *input2)
{
    int result;
    pid_t variable = fork();
    if (variable < 0)
    {
        printf("Child Not Created!! Try Again.");
    }
    else if (variable == 0)
    {
        result = execl(dir, "buffer", input1, input2, NULL);
    }
    else
    {
        waitpid(variable, &result, 0);
    }
    printf("\n");
}

void help_fun(char *dir, char *input)
{
    char *masti;
    strcpy(masti, input);
    execl(dir, "buffer", "simple", input, NULL);
    printf("%s\n", masti);
}

int main()
{

    initial_size = 1000;
    current_dir = malloc(10000 * sizeof(char)); // allocation of memory
    make_dir = malloc(10000 * sizeof(char));    // allocation of memory
    date_dir = malloc(10000 * sizeof(char));    // allocation of memory
    ls_dir = malloc(10000 * sizeof(char));      // allocation of memory
    rm_dir = malloc(10000 * sizeof(char));      // allocation of memory
    cat_dir = malloc(10000 * sizeof(char));     // allocation of memory
    initial_dir = malloc(10000 * sizeof(char)); // allocation of memory

    getcwd(initial_dir, 10000);
    strcpy(make_dir, initial_dir);
    strcpy(date_dir, initial_dir);
    strcpy(ls_dir, initial_dir);
    strcpy(rm_dir, initial_dir);
    strcpy(cat_dir, initial_dir);
    strcat(make_dir, "/make_object");
    strcat(date_dir, "/date_object");
    strcat(ls_dir, "/ls_object");
    strcat(rm_dir, "/rm_object");
    strcat(cat_dir, "/cat_object");

    char input_line[1000];

    while (100)
    {
        getcwd(current_dir, 1000);
        printf("%s$ ", current_dir);
        initial_size = 1000;
        char *string = malloc(sizeof(char) * initial_size);
        fgets(string, initial_size, stdin);
        string[strlen(string) - 1] = '\0';
        strcpy(input_line, string);
        char space[] = " ";
        char *seperated_input = strtok(input_line, space);
        char *previous_input = malloc(sizeof(char) * initial_size);
        int flag = 0;

        if (string[strlen(string) - 2] == '&' && string[strlen(string) - 1] == 't')
        {
            flag = 1;
        }
        if (!flag)
        {

            if (!strcmp(seperated_input, "cat"))
            {
                seperated_input = strtok(NULL, space);
                if (seperated_input == NULL)
                {
                    printf("Please enter the name of the file\n");
                    continue;
                }
                if (!strcmp(seperated_input, "-T"))
                {
                    seperated_input = strtok(NULL, space);
                    if (seperated_input == NULL)
                    {
                        printf("Please enter the name of the file\n");
                        continue;
                    }
                    if (seperated_input[0] == '-')
                    {
                        printf("Name of the file cant start with -\n");
                        continue;
                    }
                    while (seperated_input != NULL)
                    {
                        if (seperated_input[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        two_para_func(cat_dir, "-T", seperated_input);
                        seperated_input = strtok(NULL, space);
                        if (seperated_input == NULL)
                        {
                            break;
                        }
                    }
                }
                else if (!strcmp(seperated_input, "-E"))
                {
                    seperated_input = strtok(NULL, space);
                    if (seperated_input[0] == '-')
                    {
                        printf("Name of the file cant start with -\n");
                        continue;
                    }
                    if (seperated_input == NULL)
                    {
                        printf("Please enter the name of the file\n");
                        continue;
                    }
                    while (seperated_input != NULL)
                    {
                        if (seperated_input[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        two_para_func(cat_dir, "-E", seperated_input);
                        seperated_input = strtok(NULL, space);
                        if (seperated_input == NULL)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    if (seperated_input == NULL)
                    {
                        printf("Please enter the name of the file\n");
                        continue;
                    }
                    if (seperated_input[0] == '-')
                    {
                        printf("Name of the file cant start with -\n");
                        continue;
                    }
                    while (seperated_input != NULL)
                    {
                        if (seperated_input[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        two_para_func(cat_dir, "simple", seperated_input);
                        seperated_input = strtok(NULL, space);
                        if (seperated_input == NULL)
                        {
                            break;
                        }
                    }
                }
            }
            else if (!strcmp(seperated_input, "rm"))
            {
                seperated_input = strtok(NULL, space);
                if (seperated_input == NULL)
                {
                    printf("Please enter the name of the file\n");
                    continue;
                }
                if (!strcmp(seperated_input, "-r"))
                {
                    seperated_input = strtok(NULL, space);
                    printf("%s\n", seperated_input);
                    if (seperated_input == NULL)
                    {
                        printf("Please enter the name of the file\n");
                        continue;
                    }

                    while (seperated_input != NULL)
                    {
                        if (seperated_input[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        char *seperated_input2 = malloc(1000 * sizeof(char));
                        strcpy(seperated_input2, seperated_input);
                        two_para_func(rm_dir, "-r", seperated_input);
                        seperated_input = strtok(NULL, space);
                    }
                }
                else if (!strcmp(seperated_input, "-v"))
                {
                    if (seperated_input == NULL)
                    {
                        printf("Please enter the name of the file\n");
                        continue;
                    }
                    seperated_input = strtok(NULL, space);
                    if (seperated_input[0] == '-')
                    {
                        printf("Name of the file cant start with -\n");
                        continue;
                    }
                    while (seperated_input != NULL)
                    {
                        if (seperated_input[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        char *seperated_input2 = malloc(1000 * sizeof(char));
                        strcpy(seperated_input2, seperated_input);
                        two_para_func(rm_dir, "-v", seperated_input);
                        seperated_input = strtok(NULL, space);
                    }
                }
                else
                {
                    // printf("%s\n",seperated_input);
                    if (seperated_input == NULL)
                    {
                        printf("Please enter the name of the file\n");
                        continue;
                    }
                    if (seperated_input[0] == '-')
                    {
                        printf("Name of the file cant start with -\n");
                        continue;
                    }
                    while (seperated_input != NULL)
                    {
                        if (seperated_input[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        char *seperated_input2 = malloc(1000 * sizeof(char));
                        strcpy(seperated_input2, seperated_input);
                        seperated_input = strtok(NULL, space);
                        two_para_func(rm_dir, "simple", seperated_input2);
                    }
                }
            }
            else if (!strcmp(seperated_input, "ls"))
            {

                int result;
                pid_t variable = fork();
                if (variable < 0)
                {
                    printf("Child Not Created!! Try Again.");
                }
                else if (variable == 0)
                {
                    seperated_input = strtok(NULL, space);
                    if (seperated_input == NULL)
                    {
                        result = execl(ls_dir, "buffer", "simple", NULL);
                    }
                    if (seperated_input[0] == '-')
                    {
                        printf("Name of the file cant start with -\n");
                        continue;
                    }
                    else if (!strcmp(seperated_input, "-1"))
                    {
                        char *in = malloc(1000 * sizeof(char));
                        strcpy(in, seperated_input);
                        seperated_input = strtok(NULL, space);
                        // if (seperated_input[0] == '-')
                        // {
                        //     printf("Name of the file cant start with -\n");
                        //     continue;
                        // }
                        if (seperated_input != NULL)
                        {
                            printf("Please enter command in the valid format\n");
                        }
                        else
                        {
                            result = execl(ls_dir, "buffer", in, NULL);
                        }
                    }
                    else if (!strcmp(seperated_input, "-A"))
                    {
                        char *in = malloc(1000 * sizeof(char));
                        strcpy(in, seperated_input);
                        seperated_input = strtok(NULL, space);
                        if (seperated_input[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            continue;
                        }
                        if (seperated_input != NULL)
                        {
                            printf("Please enter command in the valid format\n");
                        }
                        else
                        {
                            result = execl(ls_dir, "buffer", in, NULL);
                        }
                    }
                    else
                    {
                        printf("Please enter valid command\n");
                    }
                }
                else
                {
                    waitpid(variable, &result, 0);
                }
                printf("\n");
            }
            else if (!strcmp(seperated_input, "date"))
            {
                int result;
                pid_t variable = fork();
                if (variable < 0)
                {
                    printf("Child Not Created!! Try Again.");
                }
                else if (variable == 0)
                {
                    seperated_input = strtok(NULL, space);
                    if (seperated_input[0] == '-')
                    {
                        printf("Name of the file cant start with -\n");
                        continue;
                    }
                    if (seperated_input == NULL)
                    {
                        result = execl(date_dir, "buffer", "simple", NULL);
                    }
                    else if (!strcmp(seperated_input, "-u"))
                    {
                        char *in = malloc(1000 * sizeof(char));
                        strcpy(in, seperated_input);
                        seperated_input = strtok(NULL, space);
                        if (in[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            continue;
                        }
                        if (seperated_input != NULL)
                        {
                            printf("Please enter command in the valid format\n");
                        }
                        else
                        {
                            if (in[0] == '-')
                            {
                                printf("Name of the file cant start with -\n");
                                continue;
                            }
                            result = execl(date_dir, "buffer", in, NULL);
                        }
                    }
                    else if (!strcmp(seperated_input, "-R"))
                    {
                        char *in = malloc(1000 * sizeof(char));
                        strcpy(in, seperated_input);
                        seperated_input = strtok(NULL, space);
                        if (seperated_input != NULL)
                        {
                            printf("Please enter command in the valid format\n");
                        }
                        else
                        {
                            if (in[0] == '-')
                            {
                                printf("Name of the file cant start with -\n");
                                continue;
                            }
                            result = execl(date_dir, "buffer", in, NULL);
                        }
                    }
                    else if (seperated_input != NULL)
                    {
                        printf("Please enter command in the valid format\n");
                    }
                }
                else
                {
                    waitpid(variable, &result, 0);
                }
            }
            else if (!strcmp(seperated_input, "pwd"))
            {
                seperated_input = strtok(NULL, space);
                if (seperated_input == NULL)
                {
                    printf("%s\n", getcwd(current_dir, 1000));
                }
                else
                {
                    if (!strcmp(seperated_input, "-P"))
                    {
                        seperated_input = strtok(NULL, space);
                        if (seperated_input == NULL)
                        {
                            printf("%s\n", getcwd(current_dir, 1000));
                        }
                    }
                    else if (!strcmp(seperated_input, "-L"))
                    {
                        seperated_input = strtok(NULL, space);
                        if (seperated_input == NULL)
                        {
                            printf("%s\n", getcwd(current_dir, 1000));
                        }
                    }
                    else
                    {
                        printf("INVALID COMMAND PLEASE TRY AGAIN\n");
                    }
                }
            }
            else if (!strcmp(seperated_input, "cd"))
            {
                seperated_input = strtok(NULL, space);
                if (seperated_input == NULL)
                {
                    printf("Please specify which directory you want to get into.\n");
                }
                else if (!strcmp(seperated_input, ".."))
                {
                    previous_input = seperated_input;
                    seperated_input = strtok(NULL, space);
                    if (seperated_input == NULL)
                    {
                        int res = chdir(previous_input);
                        if (res < 0)
                        {
                            printf("Directory cannot be changed\n");
                        }
                        getcwd(current_dir, 1000);
                    }
                }
                else
                {
                    previous_input = seperated_input;
                    seperated_input = strtok(NULL, space);
                    if (seperated_input == NULL)
                    {
                        int res = chdir(previous_input);
                        if (res < 0)
                        {
                            printf("Directory cannot be changed\n");
                        }
                        getcwd(current_dir, 1000);
                    }
                    else
                    {
                        printf("INVALID COMMAND PLEASE TRY AGAIN\n");
                    }
                }
            }
            else if (!strcmp(seperated_input, "echo"))
            {
                seperated_input = strtok(NULL, space);
                if (seperated_input == NULL)
                {
                    printf("INVALID COMMAND PLEASE TRY AGAIN\n");
                }
                int flag = 0;
                if (!strcmp(seperated_input, "-n"))
                {
                    seperated_input = strtok(NULL, space);
                    flag = 1;
                }
                else if (!strcmp(seperated_input, "-e"))
                {
                    seperated_input = strtok(NULL, space);
                }
                printf("%s", seperated_input);
                seperated_input = strtok(NULL, space);
                while (seperated_input != NULL)
                {
                    printf(" %s", seperated_input);
                    seperated_input = strtok(NULL, space);
                }
                if (!flag)
                {
                    printf("\n");
                }
            }
            else if (!strcmp(seperated_input, "mkdir"))
            {

                int result;
                char *seperated_input2 = strtok(string, space);
                seperated_input = strtok(NULL, space);
                if (seperated_input == NULL)
                {
                    printf("Please enter the name of the file\n");
                    continue;
                }
                char slash[] = "/";
                if (!strcmp(seperated_input, "-p"))
                {

                    seperated_input2 = strtok(NULL, space);
                    if (seperated_input2 == NULL)
                    {
                        printf("Please enter the name of the file\n");
                        continue;
                    }
                    if (seperated_input2[0] == '-')
                    {
                        printf("Name of the file cant start with -\n");
                        continue;
                    }
                    if (seperated_input2 != NULL)
                    {
                        if (seperated_input2[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            continue;
                        }
                        char *seperated_input3 = malloc(1000 * sizeof(char));
                        char *seperated_input3_back = malloc(1000 * sizeof(char));
                        strcpy(seperated_input3, seperated_input2);
                        strcpy(seperated_input3_back, seperated_input2);
                        seperated_input3 = strtok(seperated_input3, slash);
                        int number_of_back_steps = 0;

                        while (seperated_input3 != NULL)
                        {
                            number_of_back_steps++;
                            pid_t variable = fork();
                            if (variable < 0)
                            {
                                printf("Child Not Created!! Try Again.");
                            }
                            else if (variable == 0)
                            {
                                int out = execl(make_dir, "buffer", "simple2", seperated_input3, NULL);
                            }
                            else
                            {
                                waitpid(variable, &result, 0);
                            }
                            chdir(seperated_input3);
                            seperated_input3 = strtok(NULL, slash);
                        }
                        while (number_of_back_steps--)
                        {
                            chdir("..");
                            getcwd(current_dir, 1000);
                        }
                    }
                }
                else if (!strcmp(seperated_input, "-v"))
                {
                    seperated_input = strtok(NULL, space);
                    if (seperated_input == NULL)
                    {
                        printf("Please enter the name of the file\n");
                        continue;
                    }
                    if (seperated_input[0] == '-')
                    {
                        printf("Name of the file cant start with -\n");
                        continue;
                    }
                    while (seperated_input != NULL)
                    {
                        if (seperated_input == NULL)
                        {
                            printf("Please enter the name of the file\n");
                            break;
                        }
                        pid_t variable = fork();
                        if (variable < 0)
                        {
                            printf("Child Not Created!! Try Again.");
                        }
                        else if (variable == 0)
                        {
                            int out = execl(make_dir, "buffer", "-v", seperated_input, NULL);
                        }
                        else
                        {
                            seperated_input = strtok(NULL, space);
                            waitpid(variable, &result, 0);
                        }
                    }
                }
                else
                {
                    if (seperated_input == NULL)
                    {
                        printf("Please enter the name of the file\n");
                        continue;
                    }
                    while (seperated_input != NULL)
                    {
                        if (seperated_input[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        pid_t variable = fork();
                        if (variable < 0)
                        {
                            printf("Child Not Created!! Try Again.");
                        }
                        else if (variable == 0)
                        {

                            int out = execl(make_dir, "buffer", "simple", seperated_input, NULL);
                        }
                        else
                        {
                            seperated_input = strtok(NULL, space);
                            waitpid(variable, &result, 0);
                        }
                    }
                }
            }
            else
            {
                printf("INVALID COMMAND PLEASE TRY AGAIN\n");
            }
        }
        else
        {
            if (!strcmp(seperated_input, "cat"))
            {
                seperated_input = strtok(NULL, space);
                char *seperated_input2 = malloc(1000 * sizeof(char));
                strcpy(seperated_input2, seperated_input);
                pthread_t thread_id;
                if (strcmp(seperated_input2, "-E") && strcmp(seperated_input2, "-T"))
                {
                    while (seperated_input != NULL)
                    {
                        if (seperated_input[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        if (!strcmp(seperated_input, "&t"))
                        {
                            seperated_input = strtok(NULL, space);

                            continue;
                        }
                        char *arguments = malloc(1000 * sizeof(char));
                        strcat(arguments, cat_dir);
                        strcat(arguments, " ");
                        strcat(arguments, "simple");
                        strcat(arguments, " ");
                        strcat(arguments, seperated_input);
                        strcat(arguments, "\0");
                        seperated_input = strtok(NULL, space);
                        pthread_create(&thread_id, NULL, helper_function, (void *)arguments);
                        pthread_join(thread_id, NULL);
                    }
                }
                else if (!strcmp(seperated_input2, "-E"))
                {
                    seperated_input = strtok(NULL, space);

                    while (seperated_input != NULL)
                    {
                        if (seperated_input[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        if (!strcmp(seperated_input, "&t"))
                        {
                            seperated_input = strtok(NULL, space);
                            continue;
                        }
                        char *arguments = malloc(1000 * sizeof(char));
                        strcat(arguments, cat_dir);
                        strcat(arguments, " ");
                        strcat(arguments, "-E");
                        strcat(arguments, " ");
                        strcat(arguments, seperated_input);
                        strcat(arguments, "\0");
                        seperated_input = strtok(NULL, space);
                        pthread_create(&thread_id, NULL, helper_function, (void *)arguments);
                        pthread_join(thread_id, NULL);
                    }
                }
                else if (!strcmp(seperated_input2, "-T"))
                {
                    seperated_input = strtok(NULL, space);

                    while (seperated_input != NULL)
                    {
                        if (seperated_input[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        if (!strcmp(seperated_input, "&t"))
                        {
                            seperated_input = strtok(NULL, space);
                            continue;
                        }
                        char *arguments = malloc(1000 * sizeof(char));
                        strcat(arguments, cat_dir);
                        strcat(arguments, " ");
                        strcat(arguments, "-T");
                        strcat(arguments, " ");
                        strcat(arguments, seperated_input);
                        strcat(arguments, "\0");
                        seperated_input = strtok(NULL, space);
                        pthread_create(&thread_id, NULL, helper_function, (void *)arguments);
                        pthread_join(thread_id, NULL);
                    }
                }
            }
            else if (!strcmp(seperated_input, "rm"))
            {
                seperated_input = strtok(NULL, space);
                char *seperated_input2 = malloc(1000 * sizeof(char));
                strcpy(seperated_input2, seperated_input);
                pthread_t thread_id;

                if (!strcmp(seperated_input2, "-v"))
                {
                    seperated_input = strtok(NULL, space);

                    while (seperated_input != NULL)
                    {
                        if (seperated_input[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        if (!strcmp(seperated_input, "&t"))
                        {
                            seperated_input = strtok(NULL, space);

                            continue;
                        }
                        char *arguments = malloc(1000 * sizeof(char));
                        strcat(arguments, rm_dir);
                        strcat(arguments, " ");
                        strcat(arguments, "-v");
                        strcat(arguments, " ");
                        strcat(arguments, seperated_input);
                        strcat(arguments, "\0");
                        seperated_input = strtok(NULL, space);
                        pthread_create(&thread_id, NULL, helper_function, (void *)arguments);
                        pthread_join(thread_id, NULL);
                    }
                }
                else if (!strcmp(seperated_input2, "-r"))
                {
                    seperated_input2 = strtok(NULL, space);

                    while (seperated_input2 != NULL)
                    {
                        if (seperated_input2[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        if (!strcmp(seperated_input2, "&t"))
                        {
                            break;
                        }
                        char *arguments = malloc(1000 * sizeof(char));
                        strcat(arguments, rm_dir);
                        strcat(arguments, " ");
                        strcat(arguments, "-r");
                        strcat(arguments, " ");
                        strcat(arguments, seperated_input2);
                        strcat(arguments, "\0");
                        pthread_create(&thread_id, NULL, helper_function, (void *)arguments);
                        pthread_join(thread_id, NULL);
                        seperated_input2 = strtok(NULL, space);
                    }
                }
                else
                {
                    while (seperated_input != NULL)
                    {
                        if (!strcmp(seperated_input, "&t"))
                        {
                            seperated_input = strtok(NULL, space);

                            continue;
                        }
                        if (seperated_input[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        char *arguments = malloc(1000 * sizeof(char));
                        strcat(arguments, rm_dir);
                        strcat(arguments, " ");
                        strcat(arguments, "simple");
                        strcat(arguments, " ");
                        strcat(arguments, seperated_input);
                        strcat(arguments, "\0");
                        seperated_input = strtok(NULL, space);
                        pthread_create(&thread_id, NULL, helper_function, (void *)arguments);
                        pthread_join(thread_id, NULL);
                    }
                }
            }
            else if (!strcmp(seperated_input, "ls"))
            {
                seperated_input = strtok(NULL, space);
                if (strcmp(seperated_input, "-1") && strcmp(seperated_input, "-A"))
                {
                    seperated_input = "simple";
                }
                pthread_t thread_id;
                char *arguments = malloc(1000 * sizeof(char));
                strcat(arguments, ls_dir);
                strcat(arguments, " ");
                strcat(arguments, seperated_input);
                strcat(arguments, "\0");
                printf("\n");
                pthread_create(&thread_id, NULL, helper_function, (void *)arguments);
                pthread_join(thread_id, NULL);
            }
            else if (!strcmp(seperated_input, "date"))
            {
                seperated_input = strtok(NULL, space);
                if (strcmp(seperated_input, "-R") && strcmp(seperated_input, "-u"))
                {
                    seperated_input = "simple";
                }
                pthread_t thread_id;
                char *arguments = malloc(1000 * sizeof(char));
                strcat(arguments, date_dir);
                strcat(arguments, " ");
                strcat(arguments, seperated_input);
                strcat(arguments, "\0");
                pthread_create(&thread_id, NULL, helper_function, (void *)arguments);
                pthread_join(thread_id, NULL);
            }
            else if (!strcmp(seperated_input, "mkdir"))
            {
                seperated_input = strtok(NULL, space);
                char slash[] = "/";
                if (!strcmp(seperated_input, "-p"))
                {
                    char *seperated_input2 = strtok(string, space);
                    seperated_input2 = strtok(NULL, space);
                    seperated_input2 = strtok(NULL, space);
                    // printf("%s\n",seperated_input2);
                    if (seperated_input2 != NULL)
                    {
                        char *seperated_input3 = malloc(1000 * sizeof(char));
                        char *seperated_input3_back = malloc(1000 * sizeof(char));
                        strcpy(seperated_input3, seperated_input2);
                        strcpy(seperated_input3_back, seperated_input2);
                        seperated_input3 = strtok(seperated_input3, slash);
                        int number_of_back_steps = 0;
                        while (seperated_input3 != NULL)
                        {
                            pthread_t thread_id;

                            number_of_back_steps++;
                            char *arguments = malloc(1000 * sizeof(char));
                            strcat(arguments, make_dir);
                            strcat(arguments, " ");
                            strcat(arguments, "simple");
                            strcat(arguments, " ");
                            strcat(arguments, seperated_input3);
                            strcat(arguments, "\0");
                            pthread_create(&thread_id, NULL, helper_function, (void *)arguments);
                            pthread_join(thread_id, NULL);
                            chdir(seperated_input3);
                            seperated_input3 = strtok(NULL, slash);
                        }
                        while (number_of_back_steps--)
                        {
                            chdir("..");
                            getcwd(current_dir, 1000);
                        }
                    }
                }
                else if (!strcmp(seperated_input, "-v"))
                {
                    char *seperated_input2 = strtok(string, space);
                    seperated_input2 = strtok(NULL, space);
                    seperated_input2 = strtok(NULL, space);
                    pthread_t thread_id;
                    while (100)
                    {
                        if (!strcmp(seperated_input2, "&t"))
                        {
                            break;
                        }
                        if (seperated_input2[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        char *arguments = malloc(1000 * sizeof(char));
                        strcat(arguments, make_dir);
                        strcat(arguments, " ");
                        strcat(arguments, "-v");
                        strcat(arguments, " ");
                        strcat(arguments, seperated_input2);
                        // printf("%s\n", seperated_input2);
                        strcat(arguments, "\0");
                        pthread_create(&thread_id, NULL, helper_function, (void *)arguments);
                        pthread_join(thread_id, NULL);
                        seperated_input2 = strtok(NULL, space);
                    }
                }
                else
                {
                    char *seperated_input2 = strtok(string, space);
                    seperated_input2 = strtok(NULL, space);
                    pthread_t thread_id;
                    while (100)
                    {
                        if (!strcmp(seperated_input2, "&t"))
                        {
                            break;
                        }
                        if (seperated_input2[0] == '-')
                        {
                            printf("Name of the file cant start with -\n");
                            break;
                        }
                        char *arguments = malloc(1000 * sizeof(char));
                        strcat(arguments, make_dir);
                        strcat(arguments, " ");
                        strcat(arguments, "simple");
                        strcat(arguments, " ");
                        strcat(arguments, seperated_input2);
                        strcat(arguments, "\0");
                        pthread_create(&thread_id, NULL, helper_function, (void *)arguments);
                        pthread_join(thread_id, NULL);
                        seperated_input2 = strtok(NULL, space);
                    }
                }
            }
            else
            {
                printf("INVALID COMMAND PLEASE TRY AGAIN\n");
            }
        }
    }

    return 0;
}