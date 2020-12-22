#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
        printf("%c ",p->data);
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

int Precedence(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
         return 2;
    else
        return 0;
}

char * InfixToPostfix(char * infix)
{
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));

    while(infix[i]!='\0')
    {
        if(IsOperand(infix[i]))
            postfix[j++]=infix[i++];
        else if(Precedence(infix[i])>Precedence(top->data))
          Push(infix[i++]);
        else
            postfix[j++]=Pop();

    }
    while(top!=NULL)
    {
        postfix[j++]=Pop();
    }
    postfix[j]='\0';
    return postfix;

}

int main()
{
    Push('#');
    char *infix="a+b*c";
    char *post=InfixToPostfix(infix);

    //Display();
    printf("%s ",post);


}
