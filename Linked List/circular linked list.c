#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head;

void Create(int A[],int n)
{
  int i;
  struct Node *t,*last;
  head=(struct Node*)malloc(sizeof(struct Node));
  head->data=A[0];
  head->next=head;
  last=head;

  for(i=1;i<n;i++)
  {
     t=(struct Node*)malloc(sizeof(struct Node));
     t->data=A[i];
     t->next=last->next;
     last->next=t;
     last=t;

  }
}

 void Display(struct Node *h)
 {
     do
     {
         printf("%d ",h->data);
         h=h->next;

     }
     while(h!=head);

 }

 void RDisplay(struct Node *h)
 {
     static int flag=0;
     if(h!=head || flag==0)
     {
         flag=1;
         printf("%d ",h->data);
         RDisplay(h->next);
     }
 }

 int Length(struct Node *h)
 {
     int c=0;
     do
     {
         c++;
         h=h->next;

     }
     while(h!=head);
     return c;
 }

 void Insert(struct Node *h,int index,int x)
 {
     int i;
     struct Node *t;
     t=(struct Node*)malloc(sizeof(struct Node));
     t->data=x;

     //if(index<0 || index>Length(h))
        //return;

     if(index==0)
     {
         if(head==NULL)
         {

          head=t;
          head->next=head;

         }

     else
       {

       while(h->next!=head)
     {
       h=h->next;
     }
      h->next=t;
      t->next=head;
      head=t;
       }
     }
    else
    {

        for(i=0;i<index-1;i++)
        {
            h=h->next;
        }
        t->next=h->next;
        h->next=t;
    }


     }
 int Delete(struct Node *h,int index)
 {
     struct Node *q;
     int x,i;
     if(index <1 || index>Length(head))
        return -1;
     if(index==1)
     {
         while(h->next!=head)
            h=h->next;
         x=head->data;
         if(h==head)
          {
           free(head);
           head=NULL;
          }
     else
     {
         h->next=head->next;
         free(head);
         head=h->next;
     }
    }
     else
     {
         for(i=0;i<index-2;i++)
            h=h->next;

         q=h->next;
         h->next=q->next;
         x=q->data;
         free(q);
     }
     return x;
 }

int middle(struct Node *p)
{
    struct Node *q;
    p=q;
    while(q)
    {
        q=q->next;
        if(q)q=q->next;
        if(q)p=p->next;
    }
    return p->data;
}


int main()
{
    int A[]={1,2,3,4,5};
    Create(A,5);
    //Display(head);
    //printf("\n");
    //RDisplay(head);
    //Insert(head,4,55);
    //Delete(head,1);
    //Display(head);
    printf("%d",middle(head));


}
