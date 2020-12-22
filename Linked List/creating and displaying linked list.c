#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*last,*second=NULL,*third=NULL;

void Create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
       t=(struct Node *)malloc(sizeof(struct Node));
       t->data=A[i];
       t->next=NULL;
       last->next=t;
       last=t;

    }
}

void Create1(int A[],int n)
{
    int i;
    struct Node *t,*last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++)
    {
       t=(struct Node *)malloc(sizeof(struct Node));
       t->data=A[i];
       t->next=NULL;
       last->next=t;
       last=t;

    }
}

void Display(struct Node *p)
{
 while(p!=0)
 {
     printf("%d ",p->data);
     p=p->next;
 }

}
void RDisplay(struct Node *p)
{
    if(p!=0)
    {
        Display(p->next);
        printf("%d ",p->data);

    }
}

int Count(struct Node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}

int RCount(struct Node *p)
{
    if(p==0)
        return 0;
    return RCount(p->next)+1;
}
int Sum(struct Node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;

    }
    return sum;
}

int RSum(struct Node *p)
{
    if(p==NULL)
     return 0;
    return RSum(p->next)+p->data;
}

int Max(struct Node *p)
{
    int max=0;
    while(p)
    {
        if(p->data > max)
            max=p->data;
        else
            p=p->next;
    }
    return max;
}

int RMax(struct Node *p)
{
    int x=0;
    if(p==0)
     return 0;
    else
     {
         x=RMax(p->next);
         return x>p->data?x:p->data;

     }
}

struct Node * Search(struct Node *p,int key)
{
 while(p)
 {
     if(key==p->data)
        return p;
     p=p->next;
 }
 return NULL;
}

struct Node * RSearch(struct Node *p,int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next,key);
};

struct Node* LSearch(struct Node *p,int key)
{
    struct Node *q=NULL;
    while(p!=0)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
        }
        q=p;
        p=p->next;
    }
};

void Insert(struct Node *p,int index,int x)
{
    if(index<0 || index>Count(p))
        return;
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
        for(int i=0;i<index-1;i++)
    {
        p=p->next;
    }
    t->next=p->next;
    p->next=t;
}

void InsertLast(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
        first=last=t;
    else
    {
        last->next=t;
        last=t;
    }

}

void SortedInsert(struct Node *p,int x)
{
    struct Node *t,*q=0;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
            {t->next=first;
            first=t;}
        else
            {t->next=q->next;
            q->next=t;}
    }
}

int Delete(struct Node *p,int index)
{
    struct Node *q=NULL;
    int x=-1,i;
    if(index<1 || index>Count(p))
        return -1;
    if(index==1)
    {
        p=first;
        x=first->data;
        first=first->next;
        free(p);
    }
    else
        for(i=0;i<index-1;i++)
    {
        q=p;
        p=p->next;
    }

        q->next=p->next;
        x=p->data;
        free(p);

    return x;
}

int IsSorted(struct Node *p)
{
    int x=-32768;
    while(p)
    {
        if(p->data<x)
            return 0;

        x=p->data;
        p=p->next;

    }
    return 1;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q=p->next;
    while(p!=NULL)
    {
        if(p->data!=q->data)
        {
            q=p;
            p=p->next;
        }
        else
        {
            q->next=p->next;
            free(p);
            p=q->next;
        }
    }
}

void Reverse(struct Node *p)
{
    int *A,i=0;
    A=(int *)malloc(sizeof(int)*Count(p));
    while(p)
    {
      A[i++]=p->data;
      p=p->next;
    }
    p=first;
    i--;
    while(p!=NULL)
    {
        p->data=A[i--];
        p=p->next;

    }
}
void Reverse1(struct Node *p)
{
    struct Node *q,*r;
    q=r=NULL;
    while(p)
    {
      r=q;
      q=p;
      p=p->next;
      q->next=r;
    }
    first=q;

}

void Reverse2(struct Node *p,struct Node *q)
{
    if(p)
    {
        Reverse2(p->next,p);
        p->next=q;
    }
    else
        first=q;
}
void Concatenate(struct Node *p,struct Node *q)
{
    third=p;
    while(p->next!=NULL)
    {
        p=p->next;

    }
    p->next=q;
    q=NULL;
}

void Merge(struct Node*p,struct Node *q)
{

    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }

    while(p && q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;

        }
        else
            {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;

        }
    }
    if(p)last->next=p;
    if(q)last->next=q;


}

int IsLoop()
{
    struct Node *p,*q;
    p=q=first;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;

    }
    while(p&&q  && p!=q);
    return p==q?1:0;
}
int middle(struct Node *p)
{
    struct Node *q;
    q=p;
    while(q)
    {
        q=q->next;
        if(q)q=q->next;
        if(q)p=p->next;
    }
    return p->data;
}
void DeleteOdd(struct Node *p)
{
    struct Node *q;
    while(1)
    {
        if((first->data)%2!=0)
            first=first->next;
        else
            break;
    }
    q=first;
    while(1)
    {
        p=first->next;
        if((p->data)%2!=0)
            {first->next=p->next;
            free(p);}

        else
                first=p;
        if((p->next)==NULL)
            break;
        }
        first=q;

}
int main()
{
    struct Node *temp;
    int A[]={11,22,33,44,666};
    int B[]={1,444,449,555,666};
    Create(A,5);
    Create1(B,5);
    //for creating loop
    /*struct Node *t1,*t2;
    t1=first->next->next;
    t2=t1->next->next;
    t2->next=t1;*/
    //Display(first);
    //printf("\n");
    //RDisplay(first);
    //printf("%d ",Count(first));
    //printf("%d ",RCount(first));
    //printf("%d ",Sum(first));
    //printf("%d ",RSum(first));
    //printf("%d ",Max(first));
    //printf("%d ",RMax(first));
    //temp=Search(first,4);
    //if(temp)
        //printf("key found %d\n",temp->data);
    //else
        //printf("key not found");
    //Display(first);
      //temp=RSearch(first,3);
    //if(temp)
       // printf("key found %d\n",temp->data);
    //else
        //printf("key not found\n");
    //Display(first);

      //temp=LSearch(first,3);
    //if(temp)
        //printf("key found %d\n",temp->data);
    //else
        //printf("key not found\n");
    //Display(first);
      //Insert(first,2,15);
      //Insert(first,4,145);
      //Insert(first,0,155);
      //Display(first);


      //InsertLast(5);
      //SortedInsert(first,0);
      //printf("Deleted element is:%d\n",Delete(first,5));
      //Display(first);
      //if(IsSorted(first))
        //printf("Sorted!!");
      //else
        //printf("Not Sorted");
        //RemoveDuplicate(first);
        //Display(first);
        //Reverse(first);
        //Reverse1(first);
        //Reverse2(first,NULL);
        //Display(first);
        //Display(second);
        //Concatenate(second,first);
        //Display(third);
        //Merge(first,second);
        //Display(third);
        //printf("%d",IsLoop());
        //printf("%d",middle(first));
        DeleteOdd(first);
        Display(first);

}
