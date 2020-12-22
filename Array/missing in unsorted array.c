#include<stdio.h>
int main()
{
    int A[10],l,h,d;

    for(int i=0;i<10;i++)
    {
        scanf("%d",&A[i]);
    }
    int H[12]={0,0,0,0,0,0,0,0,0,0,0,0};
    l=1;
    h=12;
    d=l-0;

    for(int i=0;i<10;i++)
    {
       H[A[i]]++;

    }
    for(int i=l;i<=h;i++)
    {
        if(H[i]==0)
            printf("%d\n",i);
    }
}
