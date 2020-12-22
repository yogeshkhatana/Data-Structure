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
void append(struct Array *arr,int x)
{

    if(arr->length<arr->size)
    {

        arr->A[arr->length++]=x;

    }

}
void insert(struct Array *arr,int index,int x)
{ int i;

    if(index>0 && index<=arr->length)
    {

        for(i=arr->length;i>index;i--)
        {

            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}
int delete(struct Array *arr,int index)
{
    int i;

    if(index>=0 && index<arr->length)
    {
        int x=arr->A[index];
        for(i=index;i<arr->length-1;i++)
        {

            arr->A[i]=arr->A[i+1];

        }
        arr->length--;
        return x;

    }
    return 0;
}
int LinearSearch(struct Array arr,int key)
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        if(arr.A[i]==key)
            return i;

    }
    return -1;
}
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}
int LinearSearch1(struct Array *arr,int key)
{
    int i;
    for(i=0;i<arr->length;i++)
    {

        if(arr->A[i]==key)
        {

            swap(&arr->A[i],&arr->A[0]);
            return i;
        }

    }
    return -1;
}
int BinarySearch(struct Array arr,int key)
{
    int h,mid;
    int l=0;
    h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
        {
            return mid;
        }
        else if(key<arr.A[mid])
        {
            h=mid-1;

        }
        else
            l=mid+1;
    }
    return -1;
}

int RBinarySearch(int a[],int l,int h,int key)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return RBinarySearch(a,l,mid-1,key);
        else
            return RBinarySearch(a,mid+1,h,key);
    }
    return -1;
}

int get(struct Array arr,int index)
{

    return arr.A[index];
}
int main()
{




	struct Array arr={{1,2,3,4,5},20,5};

	//append(&arr,20);

	//insert(&arr,2,77);
	//printf("deleted element is:%d\n",delete(&arr,2));

	//printf(":\n%d",LinearSearch(arr,6));
	//printf(":\n%d",LinearSearch1(&arr,4));
	//printf(":%d\n",BinarySearch(arr,4));
	//printf(":%d\n",RBinarySearch(arr.A,0,arr.length,2));
	//printf("%d",get(arr,3));
	//display(arr);
}

