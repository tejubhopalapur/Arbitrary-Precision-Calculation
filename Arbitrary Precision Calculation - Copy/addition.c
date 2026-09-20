#include "dll.h"

int addition(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    int carry = 0;
    int data;

    while(temp1 != NULL || temp2 != NULL)
    {
        if(temp1 != NULL && temp2 != NULL)
        {
            data = temp1->data + temp2->data + carry;

            if(data > 9)
            {
                data = data % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            dl_insert_first(headR, tailR, data);

            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }
        else if(temp1 != NULL)
        {
            data = temp1->data + carry;

            if(data > 9)
            {
                data = data % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            dl_insert_first(headR, tailR, data);

            temp1 = temp1->prev;
        }
        else
        {
            data = temp2->data + carry;

            if(data > 9)
            {
                data = data % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            dl_insert_first(headR, tailR, data);

            temp2 = temp2->prev;
        }
    }

    if(carry == 1)
    {
        dl_insert_first(headR, tailR, carry);
    }

    return SUCCESS;
}