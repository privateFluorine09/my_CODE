
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include<stdlib.h>
struct Node
{
    int number;
    struct Node* next;
};

typedef struct Node node;

void list_print(node *head)
{
    node *current;
    current=head;
    while(current!=NULL)
    {
        printf("%d ", current->number);
        current=current->next;

    }
}

node *list_push_back(node *head, int input)
{
    node *current;
    current=(node*)malloc(sizeof(node));

    if(head==NULL)
        head=current;
    else
    {
       node *list_end;
        list_end=head;

        while(list_end->next!=NULL)
        {
            list_end=list_end->next;
        }

        list_end->next=current;

    }

    current->number=input;
    current->next=NULL;

    return head;
}

node *list_push_forward(node *head, int input)
{
    node *current;
    current=(node*)malloc(sizeof(node));

    current->number=input;
    current->next=head;

    return current;

}

node *list_at(node *head, unsigned location)
{
    node *result;
    result=head;
    int i;

    for(i=0; i!=location; i++)
    result=result->next;

    return result;
}

node *list_search(node *head, int input)
{
    node *result;
    result=head;

    while(result!=NULL && (result->number)!=input)
        result=result->next;

    return result;
}

node *list_delete(node *head, node *to_delete)
{
    node *prev;
    prev=head;

    if(head==to_delete)
        head=to_delete->next;

    else
    {
        while(prev->next!=to_delete)
            prev=prev->next;

        prev->next=to_delete->next;
    }

    free(to_delete);

    return head;
}

node* list_reverse(node *head)
{
     node *current, *prev, *ptr_next;
     current=head->next;
     head->next=NULL;
     prev=head;

     while(current)
     {
         ptr_next=current->next;
         current->next=prev;
         prev=current;
         current=ptr_next;
     }

     return prev;
}



#endif // LIST_H_INCLUDED
