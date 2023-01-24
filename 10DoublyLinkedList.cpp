#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    struct Node *t,*last;

    first= new struct Node;
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new struct Node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void Delete(struct Node *p,int pos)
{
    if(pos==1)
    {
        first=first->next;
        delete p;
        if(first) first->prev=NULL;
    }
    else
    {
        for(int i=0;i<pos-1;i++) p=p->next;
        p->prev->next=p->next;

        if(p->next) p->next->prev=p->prev;
        delete p;
    }
}

void Display(struct Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int Length(struct Node *p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}

void Insert(struct Node *p,int x,int pos)
{
    struct Node *t;
    if(pos==1)
    {
        t=new struct Node;
        t->prev=NULL;
        t->data=x;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        t=new struct Node;
        t->data=x;
        for(int i=0;i<pos-1;i++) p=p->next;
        t->next=p->next;
        t->prev=p;
        if(p->next) p->next->prev=t;
        p->next=t;

    }
}

void Reverse(struct Node *p)
{
    struct Node *temp;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;

        if(p!=NULL && p->next==NULL) first=p;
    }
}

int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);
    // Display(first);
    // cout<<Length(first);

    Insert(first,4,3);
    Display(first);

    Delete(first,4);
    Display(first);

    Reverse(first);
    Display(first);

    return 0;
}