#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int size, front, rear, *q;
}queue;

void enqueue(queue *q, int x){
    if(q->rear == q->size-1)
        printf("Queue is Full\n");
    else{
        q->rear++;
        q->q[q->rear] = x;
    }
}

int dequeue(queue *q){
    int x = -1;
    if(q->front == q->rear)
        printf("Queue is Empty\n");
    else{
        q->front++;
        x = q->q[q->front];
    }
    return x;
}

void display(queue q){
    printf("Queue: ");
    while(q.front < q.rear){
        q.front++;
        printf("%d ", q.q[q.front]);
    }
    printf("\n");
}

void main(){
    queue qu;
    printf("Enter the size of the queue: ");
    scanf("%d", &qu.size);
    qu.q = (int *)malloc(qu.size*sizeof(int));
    qu.front = qu.rear = -1;
    
    enqueue(&qu, 10);
    display(qu);
    enqueue(&qu, 20);
    display(qu);
    enqueue(&qu, 30);
    display(qu);
    enqueue(&qu, 40);
    display(qu);
    dequeue(&qu);
    display(qu);
    dequeue(&qu);
    display(qu);
    dequeue(&qu);
    display(qu);
}