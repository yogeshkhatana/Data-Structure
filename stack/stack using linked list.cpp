#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
  public:
      int data;
      Node * next;

};

class Stack
{
   private:
       Node * top;
   public:
       Stack()
       {
           top=NULL;
       }
       void Push(int x);
       int Pop();
       void Display();
};

void Stack::Push(int x)
{
    Node *t;
    t=new Node;
    if(t==NULL)
    cout<<"Stack is Full\n";
    else
        {
         t->data=x;
         t->next=top;
         top=t;
        }
}

int Stack::Pop()
{
    int x=-1;
    if(top==NULL)
        cout<<"Stack is Empty\n";
    else
    {
        Node *t;
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void Stack::Display()
{
    Node *p;
    p=top;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main()
{
    Stack st;
    st.Push(12);
    st.Push(123);
    st.Push(21);
    cout<<st.Pop()<<endl;;
    st.Display();

}
