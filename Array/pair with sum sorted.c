#include<stdio.h>
int main()
{
    int A[10],n,k,i=0,j;

    printf("Enter size of Array:");
    scanf("%d",&n);
    printf("Enter element to find pair:");
    scanf("%d",&k);
    j=n-1;


  printf("Enter Elements of Array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

  for(i=0,j=n-1;i<j;)
  {
      if(A[i]+A[j]==k)
      {
          printf("%d + %d = %d\n",A[i],A[j],k);
          i++;
          j--;
      }
      else if(A[i]+A[j]<k)
      {
          i++;
      }
      else
        j--;
  }
}
