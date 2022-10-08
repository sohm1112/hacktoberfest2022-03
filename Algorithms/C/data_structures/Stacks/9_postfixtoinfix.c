#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    int size, top;
    char **s; // stack k ek block m string store krwane k liye
}Stack;

Stack create(int size){
    Stack st;
    st.size = size;
    st.top = -1;
    st.s = (char **)malloc(sizeof(char *)*st.size);
    return st;
}

void push(Stack *st, char *s){
    if(st->top==st->size-1)
        printf("Stack is Full\n");
    else
        strcpy(st->s[++st->top], s); // string ko stack block m copy krne k liye
}

void pop(Stack *st, char *s){ // char *s m mai string ki value daalunga kyoki hum 48 or 49 line m direct x1 = pop(&st) nhi kr skte kyoki C m string ese copy nhi ho skti
    if(st->top==-1)
        return;
    else{
        st->top--;
        strcpy(s, st->s[st->top+1]);
    }
}

char *postoin(char *postfix){
    char *infix;
    int len = strlen(postfix);
    Stack st = create(len); // stack initialise krdiya
    int i=0;
    while(postfix[i]!=0){
        char x3[2]; // postfix[i] ek character h... jiski vjah se strcat, strcpy vale function kaam nhi kr rhe... isliye ek string bnayi 2 length ki
        x3[1]=0; // or uska 2nd character null krdiya string terminate krne k liye or 0 index pe m postfix[i] store krwa dunga
        if(postfix[i]!='+' && postfix[i]!='-' && postfix[i]!='*' && postfix[i]!='/'){ // agr ese koi operator nhi h to direct push into the stack
            x3[0] = postfix[i++]; // x3 m postfix[i] store krwa diya... in other words character ko string bna diya
            push(&st, x3); // ab push krne m error/warning nhi de rha
        }
        else{ // jse hi mujhe postfix expression m mujhe koi operator mila m 2 strings ko pop krdunga stack m se
            char x1[len+1], x2[len+1]; 
            pop(&st, x2); // yha x1, x2 kis liye bnaye ye sb jan ne k liye kripya pop function vala comment pdhe
            pop(&st, x1);
            strcpy(infix, x1); // infix = {x1} + {operator} + {x2}
            strncat(infix, &postfix[i], 1); // strcat = 2 string concatenate krne k liye, strncat = string or ek number of characters of a string ko concatenate krne k liye
            strcat(infix, x2);
            push(&st, infix); // jo ek baar operation krne pe infix string mili usko vapis stack m push krdiya next operations k liye
        }
    }
    return infix;
}

void main(){
    char *postfix;
    printf("Enter postfix: ");
    gets(postfix);
    char *infix = postoin(postfix);
    printf("Infix: %s", infix);
}