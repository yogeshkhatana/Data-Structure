#include<stdio.h>
int main()
{
    int arr[10],l,h,d;

    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    l=arr[0];
    h=arr[9];
    d=l-0;
    for(int i=0;i<10;i++)
    {
        if(d!=arr[i]-i)
        {
            printf("Missing Element is:%d\n",i+d);
            break;
        }
    }



}
