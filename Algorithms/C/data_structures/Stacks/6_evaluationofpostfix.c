#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    int size, top;
    int *s;
}stack;

void push(stack *st, char data){
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
    st.s = (int *)malloc(sizeof(int)*st.size);

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

int Eval(char *postfix){
    stack st;
    st.size = strlen(postfix);
    st.top = -1;
    st.s = (int *)malloc(sizeof(int)*st.size);
    int i, x1, x2, r;
    for(i=0; postfix[i]!=0; i++){
        if(isOperand(postfix[i]))
            push(&st, postfix[i]-48);
        else{
            x2 = pop(&st);
            x1 = pop(&st);
            switch(postfix[i]){
                case '+':
                    r = x1+x2;
                    push(&st, r);
                    break;
                case '-':
                    r = x1-x2;
                    push(&st, r);
                    break;
                case '/':
                    r = x1/x2;
                    push(&st, r);
                    break;
                case '*':
                    r = x1*x2;
                    push(&st, r);
                    break;
            }
        }
    }
    return pop(&st);
}

void main(){
    char postfix[20];
    printf("Enter expression: ");
    gets(postfix);
    printf("Evaluation: %d", Eval(postfix));
}