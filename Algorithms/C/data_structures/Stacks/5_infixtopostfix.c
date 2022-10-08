#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    int size, top;
    char *s;
}stack;

void push(stack *st, char data){
    if(st->top == st->size-1)
        printf("Stack Overflown\n");
    else{
        st->top++;
        st->s[st->top] = data;
    }
}

char pop(stack *st){
    char x = 0;
    if(st->top == -1)
        printf("Stack Underflown\n");
    else{
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

char peek(stack st, int pos){
    char x = 0;
    if(st.top - pos + 1 < 0)
        printf("Invalid Position\n");
    else{
        x = st.s[st.top - pos + 1];
    }
    return x;
}

char stacktop(stack st){
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

int prec(char x){
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    else
        return 1;
}

char *intopost(char *infix){
    int len = strlen(infix);
    stack st;
    st.top = -1;
    st.size = len;
    st.s = (char *)malloc(sizeof(char)*len);
    char *postfix = (char *)malloc(sizeof(char)*(len+1));
    int i=0, j=0;
    while(infix[i]!=0){
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else{
            if(prec(infix[i]) > prec(stacktop(st)))
                push(&st, infix[i++]);
            else
                postfix[j++] = pop(&st);
        }
    }
    while(!isEmpty(st)){
        postfix[j++] = pop(&st);
    }
    postfix[j] = 0;
    return postfix;
}

void main(){
    char infix[20];
    printf("Enter expression: ");
    gets(infix);
    char *postfix = intopost(infix);
    puts(postfix);
}