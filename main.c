#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
typedef struct
{
    int items[maxsize];
    int top;
} stack;
 stack *initialize()
 {
     stack *s=malloc(sizeof(stack));
     s->top=0;
 }

int top(stack*s)
{
    return s->items[s->top];
}
void push (stack*s,int value)
{
    s->items[s->top]=value ;
    s->top++;
}
int pop (stack*s)
{
    s->top--;
    int x =s->items[s->top];
    return x;
}
int isfull(stack*s)
{
    if(s->top==maxsize)
        return 1;
    else
    return 0;
}
int isempty(stack *s)
{
    if(s->top==0)
        return 1;
    else
        return 0;
}
void display (stack*s)
{
    stack*s1=initialize();
    while(!isempty(s))
    {
        int x=pop(s);
        printf("%d",x);
        push(s1,x);
    }
    printf("\n");
    while(!isempty(s1))
    {
        int y=pop(s1);
        push(s,y);
    }

}
int evaluate(int x,int y,char c)
{
    if(c=='+');
    return(x+y);
    if(c=='-');
    return(x-y);
    if(c=='*')
    return(x*y);
    if(c=='/')
    return (x/y);
}
int evaluatepostfix(char *str)
{
    stack*s=initialize();
    int i=0;
    int x,y,value;
    for (i=1;i<strlen(str);i++)
    {
        if(isdigit(str[i]))
        push(s,str[i]-'0');
        else {
            x=pop(s);
            y=pop(s);
            value=evaluate(x,y,str[i]);
            push(s,value);
    }
    }
    value=pop(s);
    return value;
}
int pariority (char c)
{
    switch (c)
    {
        case '*':
        case '/':
        return 1;
        case '+':
        case  '-':
        return 0;
        case '(':
        return 2;
    }
}
void print_postfix(char *str)
{
    stack*s=initialize();
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(isdigit(str))
            printf("%d",str[i]);
        else if (str[i]==')')
                    while(!isempty(s)&&top(s)!=')')
        {
            printf("%c",pop(s));
        }
        pop(s);
    }
    else if(isempty(s))
        push(s,str[i]);


}
int main()
{
   stack*s=initialize();
   evaluatepostfix();
   display(s);
    return 0;
}
