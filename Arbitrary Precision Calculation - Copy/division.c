#include "dll.h"

int division(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR)
{
    Dlist *temp1;

    Dlist *head3 = NULL;
    Dlist *tail3 = NULL;

    Dlist *headSub = NULL;
    Dlist *tailSub = NULL;

    int count;

    *headR = NULL;
    *tailR = NULL;

    if(*head2 == NULL)
    {
        return FAILURE;
    }

    if((*head2)->data == 0 && (*head2)->next == NULL)
    {
        printf("Division by zero is not possible\n");
        return FAILURE;
    }

    temp1 = *head1;

    while(temp1 != NULL)
    {
        dl_insert_last(&head3, &tail3, temp1->data);

        while(head3 != NULL &&
              head3->data == 0 &&
              head3->next != NULL)
        {
            Dlist *temp = head3;

            head3 = head3->next;
            head3->prev = NULL;

            free(temp);
        }

        count = 0;

        while(head3 != NULL && list_compare(head3, *head2) >= 0)
        {
            headSub = NULL;
            tailSub = NULL;

            sub(&head3, &tail3,
                head2, tail2,
                &headSub, &tailSub);

            delete_list(&head3, &tail3);

            head3 = headSub;
            tail3 = tailSub;

            count++;
        }

        dl_insert_last(headR, tailR, count);

        temp1 = temp1->next;
    }

    delete_list(&head3, &tail3);

    return SUCCESS;
}