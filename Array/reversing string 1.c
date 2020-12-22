#include<stdio.h>
int main()
{
    char A[]="Hello World",t;
    int i,j;
    for(i=0;A[i]!='\0';i++)
    {

    }
    j=i-1;
    for(i=0;i<j;i++,j--)
    {
        t=A[i];
        A[i]=A[j];
        A[j]=t;
    }
    printf("Reverse is:%s",A);
}
