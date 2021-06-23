#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_argv(char **argv)
{
    int i;
    
    i = 0;
    printf("========argv address========\n");
    while (argv[i] != NULL)
    {
        printf("argv[%d] : %p\n", i, argv[i]);
        i++;
    }
}

void free_argv(char **argv)
{
    int i;

    i = 0;
    while (argv[i] != NULL)
    {
        free(argv[i]);
        printf("i : %d\n", i);
        i++;
    }
    free(argv);
}

int main(int argc, char *argv[])
{
    print_argv(argv);
    free_argv(argv);
    
    char *str;

    printf("str adress : %p\n", &str);
    str = strdup("hello world!");
    printf("str adress : %p\n", str);

    argv[0] = str;
    print_argv(argv);
    free_argv(argv);
}