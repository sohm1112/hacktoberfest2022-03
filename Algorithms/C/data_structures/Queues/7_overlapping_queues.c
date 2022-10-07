#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int size, front, rear, *q;
}Queue;
Queue qu1, qu2;

void create(int size){
    qu1.size = qu2.size = size;
    qu1.front = qu1.rear = -1;
    qu2.front = qu2.rear = size;
    qu1.q = (int *)malloc(sizeof(int)*qu1.size);
    qu2.q = qu1.q + qu1.size;
}

void enqueue(Queue *qu, int data){
    if(qu==&qu1){
        if(qu->rear==qu2.front-1)
            printf("Queue is Full\n");
        else
            qu->q[++qu->rear] = data;
    }
    else if(qu==&qu2){
        if(qu->front==qu1.rear+1)
            printf("Queue is Full\n");
        else
            qu->q[--qu->front] = data;
    }
}

void dequeue(Queue *qu){
    if(qu==&qu1){
        if(qu->front==qu->rear)
            printf("Queue is Empty\n");
        else
            qu->front++;
    }
    else if(qu==&qu2){
        if(qu->rear==qu->front)
            printf("Queue is Empty\n");
        else
            qu->rear--;
    }
}

void display(){
    printf("Overlapped Queue: ");
    int i=0;
    while(i<=qu1.front && qu1.front!=-1){
        printf("x ");
        i++;
    }
    while(i<=qu1.rear && qu1.rear!=-1){
        printf("%d ", qu1.q[i]);
        i++;
    }
    while(i<qu2.front){
        printf("x ");
        i++;
    }
    while(i<qu2.rear){
        printf("%d ", qu2.q[i]);
        i++;
    }
    while(i<qu2.size){
        printf("x ");
        i++;
    }
    printf("\n");
}

void main(){
    int n;
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    create(n);

    display();
    enqueue(&qu1, 10);
    display();
    enqueue(&qu2, -10);
    display();
    enqueue(&qu1, 20);
    display();
    enqueue(&qu2, -20);
    display();
    enqueue(&qu1, 30);
    display();
    enqueue(&qu2, -30);
    display();

    dequeue(&qu1);
    display();
    dequeue(&qu2);
    display();
    dequeue(&qu1);
    display();
    dequeue(&qu2);
    display();
    dequeue(&qu1);
    display();
    dequeue(&qu2);
    display();
}