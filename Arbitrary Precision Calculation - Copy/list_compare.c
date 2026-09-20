#include "dll.h"

int list_compare(Dlist *head1, Dlist *head2)
{
    int count1 = 0;
    int count2 = 0;

    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    /* Count number of digits in list1 */
    while(temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }

    /* Count number of digits in list2 */
    while(temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }

    /* Compare number of digits */
    if(count1 > count2)
    {
        return 1;
    }
    else if(count1 < count2)
    {
        return -1;
    }

    /* Same number of digits, compare digit by digit */
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data > head2->data)
        {
            return 1;
        }
        else if(head1->data < head2->data)
        {
            return -1;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return 0;
}