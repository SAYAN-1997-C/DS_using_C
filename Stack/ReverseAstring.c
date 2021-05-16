#include<stdio.h>

int main()
{
    char stk[100];
    int top=-1;
    printf("\nEnter the String : ");
    while(1)
    {
        char ch=getchar();
        if(ch=='\n')
            break;
        stk[++top]=ch;
    }
    printf("\nReverse string is : ");
    for(int i=top;i>=0;i--)
    {
        printf("%c",stk[i]);
    }
    printf("\n\n");
    return 0;
}