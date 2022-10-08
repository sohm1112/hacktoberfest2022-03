#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;
Node *front=NULL, *rear=NULL;

void enqueue(int x){
    Node *t = (Node *)malloc(sizeof(Node));
    if(t==NULL)
        printf("Queue is Full\n");
    else{
        t->data = x;
        t->next = NULL;
        if(front==NULL)
            front = t, rear = t;
        else{
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue(){
    int x = -1;
    Node *p;
    if(front==NULL)
        printf("Queue is Empty\n");
    else{
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void display(Node *p){
    printf("Queue: ");
    while(p!=0){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void main(){
    enqueue(10);
    display(front);
    enqueue(20);
    display(front);
    enqueue(30);
    display(front);
    enqueue(40);
    display(front);
    dequeue();
    display(front);
    dequeue();
    display(front);
    dequeue();
    display(front);
}