#include "dir_file.h"
#include "utils.h"

int open_file(char *fname, FILE **input)
{
    if (access(fname, F_OK) == -1)
    {
        ERR_PRINT("The '%s' file does not exists\n", fname);
        return -1;
    }

    *input = fopen(fname, "r");
    if (input == NULL)
    {
        ERR_PRINT("Failed open '%s' file\n", fname);
        return -1;
    }

    return 1;
}

// This parse_str_to_list() split string to the tokens, and put the tokens in token_list.
// The value of return is the number of tokens.
int parse_str_to_list(const char *str, char **token_list)
{
    /* Fill this function */
    int token_num = 0;
    char *ptr = malloc(sizeof(char) * strlen(str) + 1);
    strcpy(ptr, str);
    ptr[strlen(ptr) - 1] = '\0';
    // printf("%s", ptr);

    char *token_tmp = strtok(ptr, "/");
    int i = 0;

    char *null = '\0';

    while (token_tmp != NULL)
    {
        token_list[token_num] = malloc(sizeof(char) * (1 + strlen(token_tmp)));
        strcpy(token_list[token_num], token_tmp);
        token_list[token_num][strlen(token_tmp) + 1] = '\0';
        token_tmp = strtok(NULL, "/");
        //    printf("%s", token_list[token_num]);
        token_num++;
    }
    return token_num;
}
void free_token_list(char **token_list, int num_token)
{
    int index;

    for (index = 0; index < num_token; index++)
    {
        free(token_list[index]);
    }

    free(token_list);
}
