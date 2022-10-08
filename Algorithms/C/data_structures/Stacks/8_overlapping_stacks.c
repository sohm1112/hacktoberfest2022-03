#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int size, top, bottom, *s;
}Stack;
Stack st1, st2;

Stack create(int size){
    Stack st;
    st.size = size;
    st.top = -1;
    st.bottom = size;
    st.s = (int *)malloc(sizeof(int)*st.size);
    return st;
}

void push(Stack *st, int data){
    if(st==&st1){
        if(st->top!=st2.bottom-1)
            st->s[++st->top] = data;
        else
            printf("Stack is Full\n");
    }
    else if(st==&st2){
        if(st->bottom!=st1.top+1)
            st->s[--st->bottom] = data;
        else
            printf("Stack is Full\n");
    }
}

void pop(Stack *st){
    if(st==&st1){
        if(st->top==-1)
            printf("Stack is Empty\n");
        else
            st->top--;
    }
    else if(st==&st2){
        if(st->bottom==st->size)
            printf("Stack is Empty\n");
        else
            st->bottom++;
    }
}

void display(){
    printf("Overlapped Stack: ");
    for(int i=0; i<=st1.top; i++)
        printf("%d ", st1.s[i]);
    for(int i=st1.top+1; i<st2.bottom; i++)
        printf("x ");
    for(int i=st2.bottom; i<st2.size; i++)
        printf("%d ", st2.s[i]);
    printf("\n");
}

void main(){
    int n;
    printf("Enter size of Stack: ");
    scanf("%d", &n);
    st1 = create(n);
    st2 = create(n);
    push(&st1, 10);
    display();
    push(&st2, -10);
    display();
    push(&st1, 20);
    display();
    push(&st2, -20);
    display();
    push(&st1, 30);
    display();
    push(&st2, -30);
    display();
    pop(&st1);
    display();
    pop(&st2);
    display();
    display();
    pop(&st1);
    display();
    pop(&st2);
    display();
    display();
    pop(&st1);
    display();
    pop(&st2);
    display();
}