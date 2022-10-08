#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int size, front, rear, *q;
}queue;

void enqueuelast(queue *q, int x){
    if(q->rear == q->size-1)
        printf("Queue is Full\n");
    else{
        q->rear++;
        q->q[q->rear] = x;
    }
}

void enqueuefront(queue *q, int x){
    if(q->front == -1)
        printf("Queue is full\n");
    else{
        q->q[q->front] = x;
        q->front--;
    }
}

int dequeuefront(queue *q){
    int x = -1;
    if(q->front == q->rear)
        printf("Queue is Empty\n");
    else{
        q->front++;
        x = q->q[q->front];
    }
    return x;
}

int dequeuelast(queue *q){
    int x = -1;
    if(q->rear == q->front)
        printf("Queue is Empty\n");
    else{
        x = q->q[q->rear];
        q->rear--;
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
    enqueuelast(&qu, 10);
    display(qu);
    enqueuelast(&qu, 20);
    display(qu);
    enqueuelast(&qu, 30);
    display(qu);
    dequeuefront(&qu);
    display(qu);
    dequeuefront(&qu);
    display(qu);
    enqueuefront(&qu, 40);
    display(qu);
    enqueuefront(&qu, 50);
    display(qu);
    dequeuelast(&qu);
    display(qu);
    dequeuelast(&qu);
    display(qu);
}