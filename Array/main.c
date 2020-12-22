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
void Swap(int *x,int *y)
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

            Swap(&arr->A[i],&arr->A[0]);
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

int Get(struct Array arr,int index)
{
   if(index>=0 && index<=arr.length)
      return arr.A[index];
   return -1;
}
void Set(struct Array *arr,int index,int x)
{
    arr->A[index]=x;

}
int Max(struct Array arr)
{
    int m=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {

        if(m<arr.A[i])
            m=arr.A[i];
    }
    return m;
}
int Min(struct Array arr)
{
    int m=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {

        if(m>arr.A[i])
            m=arr.A[i];
    }
    return m;
}
int Sum(struct Array arr)
{ int s=0;
    for(int i=0;i<arr.length;i++)
    {
      s=s+arr.A[i];
    }
    return s;
}
float Avg(struct Array arr)
{

    return (float)Sum(arr)/arr.length;
}
void Reverse(struct Array *arr)
{
   int i,j,*B;
   B=(int*)malloc(arr->length*sizeof(int));
   for(i=arr->length-1,j=0;i>=0;i--,j++)
   {
       B[j]=arr->A[i];
   }
   for(int i=0;i<arr->length;i++)
   {
       arr->A[i]=B[i];
   }
}

void Reverse2(struct Array *arr)
{
    int i,j;

    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
      Swap(&arr->A[i],&arr->A[j]);

    }
}
void Insert(struct Array *arr,int x)
{
    int i=arr->length-1;
    if(arr->size == arr->length)
        return;
  while(i>=0 && arr->A[i]>x)
  {
      arr->A[i+1]=arr->A[i];
      i--;
  }
  arr->A[i+1]=x;
  arr->length++;
}

int IsSorted(struct Array arr)
{

    for(int i=0;i<arr.length-1;i++)
    {
       if(arr.A[i]>arr.A[i+1])
        return 0;
    }
    return 1;
}

int Rearrange(struct Array *arr)
{
    int i=0,j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j)
            Swap(&arr->A[i],&arr->A[j]);
    }
}
struct Array* Merge(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=0,j=0,k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {

        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
        }
        else
            arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
    {

        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr1->length;j++)
    {

        arr3->A[k++]=arr2->A[j];
    }


    arr3->length=arr1->length+arr2->length;
    arr3->size=10;
    return arr3;



}
struct Array* Union(struct Array *arr1,struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
      if(arr1->A[i]<arr2->A[j])
      {
          arr3->A[k++]=arr1->A[i++];

      }
      else if(arr1->A[i]>arr2->A[j])
      {
          arr3->A[k++]=arr2->A[j++];
      }
      else
        {arr3->A[k++]=arr1->A[i++];
         j++;}
    }
    for(;i<arr1->length;i++)
    {
        arr3->A[k++]=arr1->A[i];
    }
     for(;j<arr2->length;j++)
    {
        arr3->A[k++]=arr2->A[j];
    }
    arr3->length=k;
    arr3->size=10;
    return arr3;


};

struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
      if(arr1->A[i]<arr2->A[j])
      {
          i++;

      }
      else if(arr1->A[i]>arr2->A[j])
      {
          j++;
      }
      else if(arr1->A[i]==arr2->A[j])
        {arr3->A[k++]=arr1->A[i++];
         j++;}
    }

    arr3->length=k;
    arr3->size=10;
    return arr3;


};

struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
      if(arr1->A[i]<arr2->A[j])
      {
          arr3->A[k++]=arr1->A[i++];

      }
      else if(arr1->A[i]>arr2->A[j])
      {
          j++;
      }
      else
        {i++;
         j++;}
    }
 for(;i<arr1->length;i++)
    {
        arr3->A[k++]=arr1->A[i];
    }
    arr3->length=k;
    arr3->size=10;
    return arr3;


};



int main()
{




	struct Array arr={{1,2,3,4,-5},20,5};
	struct Array arr1={{0,6,7,8,9,},10,5};
	struct Array arr2={{1,2,4,5,6},10,5};
	struct Array *arr3;

	//append(&arr,20);

	//insert(&arr,2,77);
	//printf("deleted element is:%d\n",delete(&arr,2));

	//printf(":\n%d",LinearSearch(arr,6));
	//printf(":\n%d",LinearSearch1(&arr,4));
	//printf(":%d\n",BinarySearch(arr,4));
	//printf(":%d\n",RBinarySearch(arr.A,0,arr.length,2));
    //printf("%d",Get(arr,3));
    //Set(&arr,2,35);
    //printf("%d",Max(arr));
    //printf("%d",Min(arr));
     //printf("%d",Sum(arr));
    //printf("%f",Avg(arr));
     //Reverse(&arr);
     //Reverse2(&arr);
     //Insert(&arr,4);
     //printf("%d\n",IsSorted(arr));
     //Rearrange(&arr);

	//display(arr);
	//arr3=Merge(&arr1,&arr2);
	//display(*arr3);
      //arr3=Union(&arr1,&arr2);
      //display(*arr3);
      //arr3=Intersection(&arr1,&arr2);
      //display(*arr3);
      arr3=Difference(&arr1,&arr2);
      display(*arr3);

}

