#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
    int size, top;
    char *s;
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

int isBalance(char *exp){
    stack st;
    st.size = sizeof(exp);
    st.top = -1;
    st.s = (char *)malloc(sizeof(char)*st.size);

    for(int i=0; exp[i]!=0; i++){
        if(exp[i]=='(')
            push(&st, exp[i]);
        else if(exp[i]==')'){
            if(isEmpty(st))
                return 0;
            pop(&st);
        }
    }
    return isEmpty(st)?1:0;
}

void main(){
    char exp[20];
    printf("Enter the expression: ");
    gets(exp);
    printf("Ans: %d", isBalance(exp));
}