#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *newnode = malloc(sizeof(Dlist));

    if(newnode == NULL)
    {
        return FAILURE;
    }

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
    }
    else
    {
        newnode->prev = *tail;
        (*tail)->next = newnode;
        *tail = newnode;
    }

    return SUCCESS;
}

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *newnode = malloc(sizeof(Dlist));

    if(newnode == NULL)
    {
        return FAILURE;
    }

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
    }
    else
    {
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    }

    return SUCCESS;
}