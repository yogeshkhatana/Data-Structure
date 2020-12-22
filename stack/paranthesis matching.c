#include<stdio.h>
#include<stdlib.h>
struct Node
{
    char data;
    struct Node *next;
}*top=NULL;

void Push(char x)
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

char Pop()
{
    char x=-1;
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

int IsBalanced(char *exp)
{
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            Push(exp[i]);
        else if(exp[i]==')')
            {
            if(top==NULL)
              return 0;
            Pop();
            }
    }
    if(top==NULL)
        return 1;
    return 0;
}

int IsBalance1(char *exp)
{
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            Push(exp[i]);

        else if((int)exp[i]-(int)top==1)
            {
                if(top==NULL)
                  return 0;
                Pop();
            }
        else if((int)exp[i]-(int)top==2)
             {
                if(top==NULL)
                  return 0;
                Pop();
            }
        else
            return 0;

    }
    if(top==NULL)
        return 1;
    else
        return 0;
}

int main()
{
    //char *exp="((a+b)*(c-d))";
    //printf("%d",IsBalanced(exp));
    char *exp="[[(a+b)*(c-d)]";
    printf("%d",IsBalanced(exp));
}
