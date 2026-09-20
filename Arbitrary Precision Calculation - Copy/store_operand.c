#include "dll.h"

int store_operand(char *str, Dlist **head, Dlist **tail)
{
    int i = 0;
    int data;

    if(str[0] == '+' || str[0] == '-')
    {
        i = 1;
    }

    while(str[i] != '\0')
    {
        data = str[i] - '0';

        if(dl_insert_last(head, tail, data) == FAILURE)
        {
            return FAILURE;
        }

        i++;
    }

    return SUCCESS;
}