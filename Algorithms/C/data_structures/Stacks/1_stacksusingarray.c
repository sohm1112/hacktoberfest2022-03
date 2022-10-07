#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int size, top, *s;
}stack;

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

int peek(stack st, int pos){
    int x = -1;
    if(st.top - pos + 1 < 0)
        printf("Invalid Position\n");
    else{
        x = st.s[st.top - pos + 1];
    }
    return x;
}

int stacktop(stack st){
    if(st.top == -1)
        return -1;
    else
        return st.s[st.top];
}

int isEmpty(stack st){
    if(st.top == -1)
        return 1;
    else
        return 0;
}

int isFull(stack st){
    if(st.top == st.size - 1)
        return 1;
    else
        return 0;
}

void display(stack st){
    printf("Stack: ");
    for(int i=0; i<=st.top; i++){
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

void main(){
    stack st;
    printf("Enter size of the stack: ");
    scanf("%d", &st.size);
    st.top = -1;
    st.s = (int *)malloc(sizeof(int)*st.size);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    display(st);
    pop(&st);
    display(st);
}