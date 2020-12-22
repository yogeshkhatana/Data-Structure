#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void Push(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Stack is Full\n");

    else
        {
            t->data=x;
            t->next=top;
            top=t;
        }
}

int Pop()
{
    int x=-1;
    struct Node *t;
    if(top==NULL)
        printf("Stack is Empty\n");

    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p=top;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");

}

int main()
{
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Display();
    printf("%d ",Pop());
    printf("%d ",Pop());

}
