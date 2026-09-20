#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

int dl_insert_last(Dlist **head, Dlist **tail, int data);
int dl_insert_first(Dlist **head, Dlist **tail, int data);

int addition(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR);

int sub(Dlist **head1, Dlist **tail1,
        Dlist **head2, Dlist **tail2,
        Dlist **headR, Dlist **tailR);

int multiplication(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   Dlist **headR, Dlist **tailR);

int division(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR);

int delete_list(Dlist **head, Dlist **tail);

int list_compare(Dlist *head1, Dlist *head2);

void print_list(Dlist *head);
int validate_operand(char *str);
int store_operand(char *str, Dlist **head, Dlist **tail);

extern int flag;

#endif