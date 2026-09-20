#include "dll.h"

int flag = 0;

int sub(Dlist **head1, Dlist **tail1,
        Dlist **head2, Dlist **tail2,
        Dlist **headR, Dlist **tailR)
{
    Dlist *temp1;
    Dlist *temp2;

    int borrow = 0;
    int data;
    int ret;

    ret = list_compare(*head1, *head2);

    if(ret == 0)
    {
        temp1 = *tail2;
        temp2 = *tail1;
        flag = 1;
    }
    else
    {
        temp1 = *tail1;
        temp2 = *tail2;
        flag = 0;
    }

    while(temp1 != NULL)
    {
        data = temp1->data - borrow;

        if(temp2 != NULL)
        {
            data = data - temp2->data;
            temp2 = temp2->prev;
        }

        if(data < 0)
        {
            data = data + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        dl_insert_first(headR, tailR, data);

        temp1 = temp1->prev;
    }

    while(*headR != NULL &&
          (*headR)->data == 0 &&
          (*headR)->next != NULL)
    {
        Dlist *temp = *headR;

        *headR = (*headR)->next;
        (*headR)->prev = NULL;

        free(temp);
    }

    return SUCCESS;
}