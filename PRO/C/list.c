#include<stdio.h>
#include<stdlib.h>
#include"list.h"


int main(void)
{
    struct int_list *a_list=NULL;
    int input=0;

    list_push_back(a_list, input);


    list_print(a_list);

    return 0;
}


