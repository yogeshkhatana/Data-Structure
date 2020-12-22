#include<stdio.h>
int main()
{
    int A[10],n,k;
    int H[15]={};
    printf("Enter size of Array:");
    scanf("%d",&n);
    printf("Enter element to find pair:");
    scanf("%d",&k);


  printf("Enter Elements of Array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(H[k-A[i]]!=0)
            printf("%d + %d = %d\n",A[i],k-A[i],k);

        H[A[i]]++;
    }
    for(int i=0;i<15;i++)
    {
        printf("%d\t",H[i]);
    }
}

