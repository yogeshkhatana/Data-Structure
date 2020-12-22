#include<stdio.h>
int main()
{

    char A[]="finding";
     int H=0,x=0,i;

    for(i=0;A[i]!='\0';i++)
    {
       x=1;
       x=x<<A[i]-97;
       if((x&H) >0)
                printf("%c is a Duplicate!!\n",A[i]);
         //printf("D");

       else
        H=x|H;
    }

}
