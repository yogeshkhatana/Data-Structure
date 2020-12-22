#include<stdio.h>
#include "Queue.h"
struct Node* root=NULL;

void create()
{
  struct Node *p,*t;
  int x;
  struct Queue q;
  Create(&q,100);  
  printf("Enter root value:");
  scanf("%d",&x);
  root=(struct Node *)malloc(sizeof(struct Node));
  root->data=x;
  root->lchild=root->rchild=NULL;
  Enqueue(&q,root);

  while(!isEmpty(q))
  {
      p=Dequeue(&q);
      printf("Enter left child of %d:",p->data);
      scanf("%d",&x);
      if(x!=-1)
      {
          t=(struct Node *)malloc(sizeof(struct Node));
          t->data=x;
          t->lchild=t->rchild=NULL;
          p->lchild=t;
          Enqueue(&q,t);
      }

      printf("Enter right child of %d:",p->data);
      scanf("%d",&x);
      if(x!=-1)
      {
          t=(struct Node *)malloc(sizeof(struct Node));
          t->data=x;
          t->lchild=t->rchild=NULL;
          p->rchild=t;
          Enqueue(&q,t);
      }
  }
}
 
void preorder(struct Node *p)
{
    if(p)
    {
        printf("%d",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
} 

void postorder(struct Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d",p->data);
    }
} 

void inorder(struct Node *p)
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
    create();
    preorder(root);
    return  0;
}