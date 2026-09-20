#include "dll.h"

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;

    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    Dlist *headR = NULL;
    Dlist *tailR = NULL;

    int sign1 = 1;
    int sign2 = 1;
    int ret;

    if(argc != 4)
    {
        printf("Usage: ./APC.out number1 operator number2\n");
        return FAILURE;
    }

    /* Validate operator */
    if(argv[2][0] != '+' &&
       argv[2][0] != '-' &&
       argv[2][0] != 'x' &&
       argv[2][0] != '*' &&
       argv[2][0] != '/')
    {
        printf("Invalid operator\n");
        return FAILURE;
    }

    /* Validate first operand */
    if(validate_operand(argv[1]) == FAILURE)
    {
        printf("Invalid input\n");
        return FAILURE;
    }

    /* Validate second operand */
    if(validate_operand(argv[3]) == FAILURE)
    {
        printf("Invalid input\n");
        return FAILURE;
    }

    /* Get sign of first operand */
    if(argv[1][0] == '-')
    {
        sign1 = -1;
    }

    /* Get sign of second operand */
    if(argv[3][0] == '-')
    {
        sign2 = -1;
    }

    /* Store operands */
    store_operand(argv[1], &head1, &tail1);
    store_operand(argv[3], &head2, &tail2);

    /*
     * Addition
     */
    if(argv[2][0] == '+')
    {
        if(sign1 == sign2)
        {
            addition(&head1, &tail1,
                     &head2, &tail2,
                     &headR, &tailR);

            if(sign1 == -1)
            {
                printf("-");
            }

            print_list(headR);
        }
        else
        {
            ret = list_compare(head1, head2);

            if(ret == 0)
            {
                dl_insert_last(&headR, &tailR, 0);
                print_list(headR);
            }
            else if(ret > 0)
            {
                sub(&head1, &tail1,
                    &head2, &tail2,
                    &headR, &tailR);

                if(sign1 == -1)
                {
                    printf("-");
                }

                print_list(headR);
            }
            else
            {
                sub(&head1, &tail1,
                    &head2, &tail2,
                    &headR, &tailR);

                if(sign2 == -1)
                {
                    printf("-");
                }

                print_list(headR);
            }
        }
    }

    /*
     * Subtraction
     */
    else if(argv[2][0] == '-')
    {
        /*
         * A - B
         * If signs are different, perform addition.
         */
        if(sign1 != sign2)
        {
            addition(&head1, &tail1,
                     &head2, &tail2,
                     &headR, &tailR);

            if(sign1 == -1)
            {
                printf("-");
            }

            print_list(headR);
        }
        else
        {
            ret = list_compare(head1, head2);

            if(ret == 0)
            {
                dl_insert_last(&headR, &tailR, 0);
                print_list(headR);
            }
            else if(ret > 0)
            {
                sub(&head1, &tail1,
                    &head2, &tail2,
                    &headR, &tailR);

                if(sign1 == -1)
                {
                    printf("-");
                }

                print_list(headR);
            }
            else
            {
                sub(&head1, &tail1,
                    &head2, &tail2,
                    &headR, &tailR);

                if(sign1 == 1)
                {
                    printf("-");
                }

                print_list(headR);
            }
        }
    }

    /*
     * Multiplication
     */
    else if(argv[2][0] == 'x' || argv[2][0] == '*')
    {
        multiplication(&head1, &tail1,
                       &head2, &tail2,
                       &headR, &tailR);

        /*
         * If result is zero, don't print negative sign.
         */
        if(!(headR->data == 0 && headR->next == NULL))
        {
            if(sign1 != sign2)
            {
                printf("-");
            }
        }

        print_list(headR);
    }

    /*
     * Division
     */
    else if(argv[2][0] == '/')
    {
        if(head2->data == 0 && head2->next == NULL)
        {
            printf("Division by zero is not possible\n");
        }
        else
        {
            division(&head1, &tail1,
                     &head2, &tail2,
                     &headR, &tailR);

            if(!(headR->data == 0 && headR->next == NULL))
            {
                if(sign1 != sign2)
                {
                    printf("-");
                }
            }

            print_list(headR);
        }
    }

    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    return SUCCESS;
}