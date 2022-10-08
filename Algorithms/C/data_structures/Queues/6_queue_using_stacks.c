#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int size, top, *s;
}stack;
stack st1, st2;

stack create(int size){
    stack st;
    st.size = size;
    st.top = -1;
    st.s = (int *)malloc(sizeof(int)*st.size);
    return st;
}

void push(stack *st, int data){
    if(st->top == st->size-1)
        printf("Stack Overflown\n");
    else{
        st->top++;
        st->s[st->top] = data;
    }
}

int pop(stack *st){
    int x = -1;
    if(st->top == -1)
        printf("Stack Underflown\n");
    else{
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

void enqueue(int key){
    while(st2.top!=-1)
        push(&st1, pop(&st2));
    push(&st1, key);
}

int dequeue(){
    int x;
    if(st2.top==-1 && st1.top==-1)
        x=0;
    else if(st1.top==-1 && st2.top!=-1)
        x = pop(&st2);
    else{
        while(st1.top!=-1)
            push(&st2, pop(&st1));
        x = pop(&st2);
    }
    while(st2.top!=-1)
        push(&st1, pop(&st2));
    return x;
}

void display(stack st){
    printf("Stack: ");
    for(int i=st.top; i>=0; i--){
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

void main(){
    int n;
    printf("Enter the size of stack: ");
    scanf("%d", &n);
    st1 = create(n);
    st2 = create(n);

    enqueue(10);
    display(st1);
    enqueue(20);
    display(st1);
    enqueue(30);
    display(st1);
    enqueue(40);
    display(st1);
    dequeue();
    display(st1);
    dequeue();
    display(st1);
}