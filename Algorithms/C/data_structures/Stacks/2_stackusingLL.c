#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;
Node *top;

void push(int x){
    Node *new = (Node *)malloc(sizeof(Node));
    if(new==NULL)
        printf("Stack Overflown\n");
    else{
        new->data = x;
        new->next = top;
        top = new;
    }
}

int pop(){
    Node *p;
    int x = -1;
    if(top == NULL)
        printf("Stack is Empty");
    else{
        p = top;
        top = top->next;
        free(p);
    }
    return x;
}

int peek(int pos){
    int x = -1;
    Node *p = top;
    for(int i=0; p!=0 && i<pos-1; i++){
        p = p->next;
    }
    if(p)
        return p->data;
    else
        return -1;
}

int stacktop(){
    return top->data;
}

int isEmpty(){
    return (top)?0:1;
}

int isFull(){
    Node *new = (Node *)malloc(sizeof(Node));
    int r = (new)?1:0;
    free(new);
    return r;
}

void main(){

}