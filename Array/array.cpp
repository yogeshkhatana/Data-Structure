#include<iostream>
using namespace std;
template <class T>
class Array
{
private:
    T *A;
    int size;
    int length;
public:
    Array()
{
    size=10;
    length=0;
    A=new T[size];
}
 Array(int sz)
{
    size=sz;
    length=0;
    A=new T[size];
}
~Array()
{

    delete []A;
}
 void Display();
 void Insert(int index,T x);
};
template <class T>
void Array<T>::Display()
{
	int i;
	for(i=0;i<length;i++)
        cout<<A[i]<<" ";
	cout<<endl;
}
template <class T>
void Array<T>::Insert(int index,T x)
{

    if(index>=0 && index<=length)
    {
    for(int i=length-1;i>=index;i--)
    {
        A[i+1]=A[i];


    }
    A[index]=x;
    length++;
    }
}

int main()
{
    Array<float> arr(10);
    arr.Insert(0,1);    arr.Insert(1,20.4);    arr.Insert(2,5);

    arr.Display();
}
