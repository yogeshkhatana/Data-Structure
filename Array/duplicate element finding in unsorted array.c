#include<stdio.h>
int main()
{
    int arr[10],count;

    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<10-1;i++)
    {count=1;
        if(arr[i]!=-1)
        {
            for(int j=i+1;j<10;j++)
            {
                if(arr[i]==arr[j])
                {
                    arr[j]=-1;
                    count++;
                }
            }
if(count>1)
        printf("%d occurs %d times\n",arr[i],count);
        }


    }
}
