#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[],int n)
{
    struct Node *t,*last;

    first=(struct Node*)malloc(sizeof(struct Node));
    first->prev=NULL;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }

}

int Length(struct Node *p)
{
    int c=0;
    while(p)
    {
      c++;
      p=p->next;
    }
    return c;
}

void Display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    if(index<0 || index>Length(p))
        return;
    if(index==0)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
     }
     else
     {
         for(int i=0;i<index-1;i++)
            p=p->next;

             t=(struct Node *)malloc(sizeof(struct Node));
             t->data=x;
             t->next=p->next;
             t->prev=p;
             if(p->next)
                p->next->prev=t;
             p->next=t;

     }

}

int Delete(struct Node *p,int index)
{
  int x,i;
  if(index<1 || index>Length(p))
    return -1;

  if(index==1)
  {
      x=p->data;
      first=first->next;

      if(first)
        first->prev=NULL;
      free(p);

  }
  else
  {
      for(i=0;i<index-1;i++)
      {
          p=p->next;
      }
      x=p->data;
      p->prev->next=p->next;
      if(p->next)
        p->next->prev=p->prev;
      free(p);
  }
  return x;
}

void Reverse(struct Node *p)
{
  struct Node *temp;
    while(p)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;

        if(p!=NULL && p->next==NULL)
            first=p;
    }

}

int main()
{
    int A[]={1,2,3,4,5};
    Create(A,5);
    //printf("Length is:%d\n",Length(first));
    //Insert(first,4,33);
    //Delete(first,3);
    Reverse(first);
    Display(first);
}
