#include<iostream>
using namespace std;
int main()
{
    int count=0,max=0,x,c;
    int arr[130]={0};


    char a[]="aaaabbbbbbbabbccdd";
    for(int i=0;a[i]!='\0';i++)
    {
        x=a[i];
        arr[x]+=1;

    }
    for(int i=0;i<130;i++)
    {
        if(arr[i]!=0)
        {
         //cout<<arr[i]<<" ";
        }
    }
  cout<<endl;
    for(int i=0;i<130;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
            c=i;
        }
    }

    cout<<max<<" And value is:"<<char(c);

}
