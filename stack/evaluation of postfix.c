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
int IsOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
      return 0;
    else return 1;
}

int Eval(char *postfix)
{
    int i;
    int x1,x2,r;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(IsOperand(postfix[i]))
            Push(postfix[i]-'0');
        else
        {
            x2=Pop();
            x1=Pop();

            switch(postfix[i])
            {
                case'+':r=x1+x2;break;
                case '-':r=x1-x2;break;
                case '*':r=x1*x2;break;
                case'/':r=x1/x2;break;
            }
            Push(r);
        }

    }
    return top->data;
}




int main()
{
    char *postfix="234*+82/-";
    printf("Result is:%d",Eval(postfix));

}
