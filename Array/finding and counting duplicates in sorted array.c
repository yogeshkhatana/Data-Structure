#include<stdio.h>
int main()
{
    int arr[10],lastDuplicate=0;

    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
   for(int i=0;i<10;i++)
   {

       if(arr[i]==arr[i+1] && arr[i]!=lastDuplicate)
       {
        lastDuplicate=arr[i];
        printf("%d\n",lastDuplicate);
       }

   }

   for(int i=0;i<10;i++)
   {

       if(arr[i]==arr[i+1])
       {
           int j=i+1;
           while(arr[j]==arr[i])
            j++;
           printf("%d is appearing %d times\n",arr[i],j-i);
           i=j-1;
       }
   }
}
