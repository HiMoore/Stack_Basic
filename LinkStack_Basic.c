#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100
#define error -1

typedef int Elemtype;
typedef struct node
{
    Elemtype data;
    struct node *next;
}SNode, *LinkStack;

void Init_Stack(LinkStack *Top)
{
    *Top = NULL;
}

void Push_Stack(LinkStack *Top, Elemtype X)
{
    SNode *p = (LinkStack)malloc(sizeof(SNode));
    if(!p)
        printf("Memory distribute error!\n");
    else
    {
        p->data = X;
        p->next = *Top;
        *Top = p;
        printf("%d was pushed into stack\n", X);
    }
}

void Pop_Stack(LinkStack *Top)
{
    Elemtype e;
    SNode *p;
    if(*Top == NULL)
        printf("This is a empty stack!\n");
    else
    {
        p = *Top;
        *Top = p -> next;
        e = p -> data;
        printf("%d was poped from stack\n", e);
        free(p);
    }
}

int Get_Top(LinkStack Top)
{
    Elemtype e;
    if(Top == NULL)
        return error;
    e = Top->data;
    return e;
}

void Destroy_Stack(LinkStack *Top)
{
    SNode *p, *q;
    p = *Top;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    *Top = NULL;
}


int main()
{
    LinkStack Stack;
    int i, e;
    Elemtype A[10] = {1,3,5,7,9,2,4,6,8,0};
    Init_Stack(&Stack);
    for(i=0; i<10; i++)
        Push_Stack(&Stack, A[i]);
    for(i=0; i<5; i++)
        Pop_Stack(&Stack);
    e = Get_Top(Stack);
    printf("The top is %d", e);
    Destroy_Stack(&Stack);
    return 0;
}
