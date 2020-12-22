#include<stdio.h>
#include<stdlib.h>
struct Array
{
	int A[20];
	int size;
	int length;
}arr;
void display(struct Array arr)
{
	int i;
	for(i=0;i<arr.length;i++)
	{
		printf("%d ",arr.A[i]);
	}
}
int main()
{




	struct Array arr={{1,2,3,4,5},20,6};
	display(arr);
}

