#include<stdio.h>
int main()
{
    int A[10],n,max,min;

    printf("Enter size of Array:");
    scanf("%d",&n);



  printf("Enter Elements of Array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    max=A[0];
    min=A[0];

    for(int i=1;i<n;i++)
    {
        if(A[i]<min)
            min=A[i];
        else if(A[i]>max)
            max=A[i];
    }
    printf("MAX : %d\n MIN : %d",max,min);
}
