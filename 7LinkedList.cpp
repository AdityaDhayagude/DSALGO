#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}
*first=NULL,*second=NULL,*third=NULL;//GLOBAL POINTER

/// @brief 
/// @param A 
/// @param n 
void create(int A[],int n)
{
    // int i;
    struct Node *t,*last;
    first=new struct Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new struct Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void create2(int A[],int n)
{
    int i;
    struct Node *t,*last;
    second=new struct Node;
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++)
    {
        t=new struct Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

void RecurDisplay(struct Node *p)
{
    if(p)
    {
        cout<<p->data;
        cout<<" ";
        RecurDisplay(p->next);
    } 
}

int countNodes(struct Node *p)
{
    if(p==0)
    {
        return 0;
    }

    int count=0;

    while(p)
    {
        count++;
        p=p->next;
    }

    return count;
}

int RecurCount(struct Node *p)
{
    if(p==0)
    {
        return 0;
    }
    else
    {
        return 1+RecurCount(p->next);
    }
}

int SumOfAllElemenets(struct Node *p)
{
    int sum=0;
    while (p)
    {
        sum+=p->data;
        p=p->next;
    }

    return sum;
    
}

int RecurAdd(struct Node *p)
{
    if(p==0)
    {
        return 0;
    }
    else return RecurAdd(p->next)+p->data;
}

int MaxEle(struct Node *p)
{
    int maax=INT_MIN;
    if(p==0)
    {
        maax=max(maax,p->data);
    }
    while(p)
    {
        maax=max(maax,p->data);
        p=p->next;
    }
    return maax;
}

struct Node* Search(struct Node *p,int key)
{
    while (p)
    {

        if(key==p->data)
        {
            return p;
        }
        p=p->next;
    }

    return NULL;
}

void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    if(index<0 || index>countNodes(p)) return;

    t=new Node;
    t->data=x;

    if(index==0)
    {
        t->next=first;
        first=t;
    }
    if(index==countNodes(p))
    {
        
    }

    else
    {
        for(int i=0;i<index-1;i++) p=p->next;
        t->next=p->next;
        p->next=t;
    }

}

void SortedInsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    t = new Node;
    t->data=x;
    t->next=NULL;


    if(first==NULL) first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

void Delete(struct Node *p,int pos)
{
    struct Node *q;
    // p=first;
    q=NULL;
    if(pos==1)
    {
        first=first->next;
        int x=p->data;
        delete p;
        return;
        
    }
    for(int i=0;i<pos-1 && p;i++)
    {
        q=p;
        p=p->next;
        if(p)
        {
            q->next=p->next;
            int x=p->data;
            delete p;
            return;
            
        }
    }

    
}

bool CheckSorted(struct Node *p)
{
    int x=INT_MIN;
    while(p)
    {
        if(p->data<x)
        {
            return false;
        }
        x=p->data;
        p=p->next;
    }
    return true;
}

void RemoveDuplicates(struct Node *p)
{
    struct Node *q=p->next;

    while(q)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}

void ReverseLinkedListViaSlidingPointers(struct Node *p)
{
    struct Node *q=NULL;
    struct Node *r=NULL;

    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first = q;
}

void Concat(struct Node *p,struct Node *q)
{
    third=p;

    while(p->next)
    {
        p=p->next;
    }
    p->next=q;
} 

void Merge(struct Node *p ,struct Node *q)
{
    struct Node *last;
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
    while(p&&q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
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
    if(p) last->next=p;
    if(q) last->next=q;
}

// int isLoop(struct Node *f)
// {
//     struct Node *p,*q;
//     p=q=f;
//     do
//     {
//         p=p->next;
//         q=q->next;
//         q=q?q->next:q;
//     }while (p && q && p!=q)
//     {
//         if(p==q) return 1;
//         else return 0;
//     }
    
    
// }

int main()
{
    int A[]={3,4,5,7,10,15};
    int B[]={2,6,11,14,19,23};
    // struct Node *temp;


    create(A,6);
    create2(B,6);

    // RecurDisplay(first);

    // cout<<countNodes(first);
    // cout<<RecurCount(first);
    // cout<<SumOfAllElemenets(first);
    // cout<<RecurAdd(first);
    // cout<<MaxEle(first);
    // temp=Search(first,5);
    // if(temp) cout<<"Key Found";
    // else cout<<"Key not found";

    // Insert(first,2,34);
    // Display(first);

    // SortedInsert(first,8);
    // Display(first);

    // Delete(first,10);
    // Display(first);

    // cout<<CheckSorted(first);

    // RemoveDuplicates(first);
    // Display(first);

    // ReverseLinkedListViaSlidingPointers(first);
    // Display(first);

    Merge(first,second);
    Display(third);
    // cout<<endl;

    // struct Node *t1,*t2;

    // t1=first->next->next;
    // t2=first->next->next->next->next;
    // t2->next=t1;

    return 0;
}