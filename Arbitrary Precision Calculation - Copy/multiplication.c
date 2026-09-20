#include "dll.h"

int multiplication(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   Dlist **headR, Dlist **tailR)
{
    Dlist *temp1;
    Dlist *temp2;

    Dlist *headR1 = NULL;
    Dlist *tailR1 = NULL;

    Dlist *headR2 = NULL;
    Dlist *tailR2 = NULL;

    int count = 0;
    int data;
    int carry;

    *headR = NULL;
    *tailR = NULL;

    temp2 = *tail2;

    while(temp2 != NULL)
    {
        carry = 0;

        headR1 = NULL;
        tailR1 = NULL;

        for(int i = 0; i < count; i++)
        {
            dl_insert_last(&headR1, &tailR1, 0);
        }

        temp1 = *tail1;

        while(temp1 != NULL)
        {
            data = (temp1->data * temp2->data) + carry;

            dl_insert_first(&headR1, &tailR1, data % 10);

            carry = data / 10;

            temp1 = temp1->prev;
        }

        if(carry != 0)
        {
            dl_insert_first(&headR1, &tailR1, carry);
        }

        headR2 = NULL;
        tailR2 = NULL;

        addition(headR, tailR,
                 &headR1, &tailR1,
                 &headR2, &tailR2);

        delete_list(headR, tailR);

        *headR = headR2;
        *tailR = tailR2;

        headR2 = NULL;
        tailR2 = NULL;

        delete_list(&headR1, &tailR1);

        temp2 = temp2->prev;

        count++;
    }

    return SUCCESS;
}