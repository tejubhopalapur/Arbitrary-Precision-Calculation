#include "dll.h"

int delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        *tail = NULL;
        return FAILURE;
    }

    while(*head != NULL)
    {
        Dlist *temp = *head;

        *head = (*head)->next;

        free(temp);
    }

    *tail = NULL;

    return SUCCESS;
}