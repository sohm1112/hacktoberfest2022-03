#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int size, top, *s;
}Stack;

Stack create(int size){
    Stack st;
    st.size = size;
    st.top = -1;
    st.s = (int *)malloc(sizeof(int)*st.size);
    return st;
}

void push(Stack *st, int data){
    if(st->top>=st->size-1)
        printf("Stack Overflow\n");
    else
        st->s[++st->top] = data;
}

void pop(Stack *st){
    if(st->top==-1)
        printf("Stack Underflown\n");
    else
        st->top--;
}

void display(Stack st){
    printf("Stack: ");
    for(int i=st.top; i>=0; i--)
        printf("%d ", st.s[i]);
    printf("\n");
}

void TOH(int a, int b, int c, int n){
    if(n>=1){
        TOH(a, c, b, n-1);
        printf("Move from %d to %d using %d\n", a, c, b);
        TOH(b, a, c, n-1);
    }
}

void main(){
    int n;
    printf("Enter number of discs: ");
    scanf("%d", &n);
    TOH(1, 2, 3, n);
}