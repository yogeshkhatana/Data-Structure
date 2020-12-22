#include<stdio.h>
int main()
{
    char A[]="madam";

    int i,j;
    for(i=0;A[i]!='\0';i++)
    {

    }
    j=i-1;
    for(i=0,j;i<j;i++,j--)
    {
        if(A[i]!=A[j])
          break;

    }
    if(A[i]==A[j])
        printf("Palindrome");
    else
    printf("Not a Palindrome");
}
