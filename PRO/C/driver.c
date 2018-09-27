#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main(void)
{
    node *head;
    head=NULL;
    int input;
    while(scanf("%d", &input))
    head=list_push_back(head, input);

    head=list_reverse(head);

    list_print(head);

    return 0;
}
