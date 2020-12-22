#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *lchild;
    Node *rchild;
};
class Queue
{
    private:
        int size;
        int front;
        int rear;
        Node **Q;
    public:
        Queue(){front=rear=-1;size=10;Q=new Node*[size];}
        Queue(int size){front=rear=-1;this->size=size;Q=new Node*[this->size];}
        void Enqueue(Node * x);
        int Dequeue();
        void Display();

};

void Queue::Enqueue(int x)
{
    if(rear==size-1)
        cout<<"Queue is Full";
    else
    {
        rear++;
        Q[rear]=x;
    }
}

Node * Queue::Dequeue()
{
    Node * x=NULL;
    if(front==rear)
        cout<<"Queue is Empty!!";
    else
    {
        front++;
        x=Q[front];
    }
    return x;
}

void Queue::Display()
{
 for(int i=front+1;i<=rear;i++)
        cout<<Q[i]<<" ";
 cout<<"\n";
}

int main()
{
  Queue q(5);
  q.Enqueue(4);
  q.Enqueue(2);
  q.Enqueue(22);
  q.Enqueue(44);
  q.Enqueue(200);
  cout<<"Deleted:"<<q.Dequeue()<<endl;

  q.Display();


}
