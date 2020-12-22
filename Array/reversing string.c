#include<stdio.h>
int main()
{
    char A[]="Hello World";
    char B[20];
    int i,j;
    for(i=0;A[i]!='\0';i++)
    {

    }
    i=i-1;
    for(j=0;i>=0;j++,i--)
    {

        B[j]=A[i];

    }
    B[j]='\0';
    printf("Reverse String : %s",B);
}
