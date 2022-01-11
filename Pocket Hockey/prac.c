#include<stdio.h>
#include<string.h>

int main()
{
    int x=256;
    char *p=&x;

    printf("%d ",p[1]);

    return 0;
}
