#include<stdio.h>
int main()
{
    int A[10],n,k;
    printf("Enter size of Array:");
    scanf("%d",&n);
    printf("Enter element to find pair:");
    scanf("%d\n",&k);


    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[i]+A[j]==k)
                printf("%d + %d = %d\n",A[i],A[j],k);
        }

    }
}
