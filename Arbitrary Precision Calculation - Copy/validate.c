#include "dll.h"

int validate_operand(char *str)
{
    int i = 0;

    if(str[i] == '+' || str[i] == '-')
    {
        i++;

        if(str[i] == '\0')
        {
            return FAILURE;
        }
    }

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return FAILURE;
        }

        i++;
    }

    return SUCCESS;
}