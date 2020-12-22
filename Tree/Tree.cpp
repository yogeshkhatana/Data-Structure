#include<iostream>
#include<stdio.h>
#include "Queue1.h"
using namespace std;
class Tree
{
    Node* root;
    public:
    
    Tree(){root=NULL;}
    void CreateTree();
    void preorder(Node *p);
    void preorder(){preorder(root);}
    void postorder(Node *p);
    void inorder(Node *p);
    void Levelorder(Node *p);
    void Height(Node *p);
};

void Tree::CreateTree()
{
  Node *p,*t;
  int x;
  Queue q(100);  
  printf("Enter root value:");
  scanf("%d",&x);
  root=new Node;
  root->data=x;
  root->lchild=root->rchild=NULL;
  q.Enqueue(root);

  while(!q.isEmpty())
  {
      p=q.Dequeue();
      printf("Enter left child of %d:",p->data);
      scanf("%d",&x);
      if(x!=-1)
      {
          t=new Node;
          t->data=x;
          t->lchild=t->rchild=NULL;
          p->lchild=t;
          q.Enqueue(t);
      }

      printf("Enter right child of %d:",p->data);
      scanf("%d",&x);
      if(x!=-1)
      {
          t=new Node;
          t->data=x;
          t->lchild=t->rchild=NULL;
          p->rchild=t;
          q.Enqueue(t);
      }
  }
}

void Tree::preorder(struct Node *p)
{
    if(p)
    {
        printf("%d",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
} 

void Tree::postorder(struct Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d",p->data);
    }
} 

void Tree::inorder(struct Node *p)
{
    if(p)
    {
        
        inorder(p->lchild);
        printf("%d",p->data);
        inorder(p->rchild);
    }
} 

int main()
{
    Tree t;
    t.CreateTree();
    t.preorder();
}