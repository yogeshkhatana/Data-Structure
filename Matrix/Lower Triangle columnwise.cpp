#include<iostream>
using namespace std;

class LowerTri
{
  private:
      int n;
      int *A;

  public:
     void Set(int i,int j,int x);
     int Get(int i ,int j);
     void Display();
     LowerTri()
     {
        n=2;
        A=new int[(2*3)/2];
     }
     LowerTri(int n)
     {
         this->n=n;
         A=new int[n*(n+1)/2];
     }
     ~LowerTri()
     {
         delete []A;
     }
};
     void LowerTri::Set(int i,int j,int x)
     {
         if(i>=j)
         {
             A[n*(j-1)-(j-1)*(j-2)/2+i-j]=x;
         }
     }

     int LowerTri::Get(int i,int j)
     {
         if(i>=j)
            return A[n*(j-1)-(j-1)*(j-2)/2+i-j];
         else
            return 0;
     }
     void LowerTri::Display()
     {
         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=n;j++)
             {
                 if(i>=j)
                 cout<<A[n*(j-1)-(j-1)*(j-2)/2+i-j]<<" ";
                 else
                    cout<<"0 ";

             }
             cout<<endl;
         }
     }

 int main()
 {
     int d,x;
     cout<<"Enter Dimension:";
     cin>>d;
     LowerTri lm(d);

     cout<<"Enter All Elements:";
     for(int i=1;i<=d;i++)
     {
         for(int j=1;j<=d;j++)
         {
             cin>>x;
             lm.Set(i,j,x);
         }
     }

     lm.Display();
 }

