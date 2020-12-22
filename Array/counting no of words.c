#include<stdio.h>
int main()
{
    int w=0;
    char A[]="How Are You";
    for(int i=0;A[i]!='\0';i++)
    {
        if(A[i]==32 && A[i-1]!=32)
            w++;
    }
    printf("No of words is:%d",w+1);
}
