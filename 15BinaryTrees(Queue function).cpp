// Queue using Array
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild; 
}

struct Queue
{
 int size;
 int front;
 int rear;
 Node **Q;
};
void create(struct Queue *q,int size)
{
 q->size=size;
 q->front=q->rear=0;
 q->Q=(Node **)malloc(q->size*sizeof(Node *));
}
void enqueue(struct Queue *q,Node * x)
{
 if(q->rear==q->size-1)
 printf("Queue is Full");
 else
 {
 q->rear++;
 q->
 Q[q->rear]=x;
 }
}
int dequeue(struct Queue *q)
{
 Node* x=NULL;
 
 if(q->front==q->rear)
 printf("Queue is Empty\n");
 else
 {
 q->front++;
 x=q->Q[q->front];
 }
 return x;
}

int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}

void Display(struct Queue q)
{
 int i;
 
 for(i=q.front+1;i<=q.rear;i++)
 printf("%d ",q.Q[i]);
 printf("\n");
}
int main()
{
 struct Queue q;
 create(&q,5);
 
 enqueue(&q,10);
 enqueue(&q,20);
 enqueue(&q,30);
 Display(q);
 
 printf("%d ",dequeue(&q));
 return 0;
} 