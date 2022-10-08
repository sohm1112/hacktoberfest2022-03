#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int front, rear, size,*q;
}Queue;

Queue create(int size){
    Queue qu;
    qu.size = size;
    qu.front = qu.rear = -1;
    qu.q = (int *)malloc(sizeof(int)*qu.size);
    return qu;
}

void enqueue(Queue *qu, int data){ // smaller number higher priority
    if(qu->rear+1==qu->size)
        printf("Queue Overflown\n");
    else{
        int i = qu->rear++;
        if(data<=qu->q[i])
            qu->q[qu->rear] = data;
        else{
            while(qu->q[i] < data){
                qu->q[i+1] = qu->q[i];
                i--;
            }
            qu->q[i+1] = data;
        }
    }
}

void dequeue(Queue *qu){
    if(qu->front!=qu->rear)
        qu->rear--;
    else
        printf("Queue is Empty\n");
}

void display(Queue qu){
    printf("Queue: ");
    for(int i=qu.front+1; i<=qu.rear; i++)
        printf("%d ", qu.q[i]);
    printf("\n");
}

void main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    Queue qu = create(n);
    printf("Enter elements in array: ");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    for(int i=0; i<n; i++){
        enqueue(&qu, arr[i]);
        display(qu);
    }
    printf("\n");
    for(int i=0; i<n; i++){
        dequeue(&qu);
        display(qu);
    }
}