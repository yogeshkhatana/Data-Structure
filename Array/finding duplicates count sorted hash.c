#include<stdio.h>
int main()
{
    int arr[10];
    int H[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<10;i++)
    {
        H[arr[i]]++;
    }
    for(int i=0;i<20;i++)
    {
        if(H[i]>1)
            printf("%d",H[i]);
    }
}
