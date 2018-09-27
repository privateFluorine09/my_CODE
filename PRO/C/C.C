#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{

    int n;
    scanf("%d", &n);
    printf("%s, %d", argv[n], argc);

    return 0;
}
