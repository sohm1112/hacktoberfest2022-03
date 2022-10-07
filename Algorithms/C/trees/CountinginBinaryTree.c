#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *lchild, *rchild;
};
struct Queue{
    int size, front, rear;
    struct Node **ptr;
};

struct Queue createQueue(int size){
    struct Queue q;
    q.size = size;
    q.front = q.rear = 0;
    q.ptr = (struct Node**)malloc(sizeof(struct Node*)*q.size);
    for(int i=0; i<size; i++){
        q.ptr[i] = NULL;
    }
    return q;
}
void enqueue(struct Queue *q, struct Node *data){
    if((q->rear+1) % q->size == q->front)
        printf("Queue is Full\n");
    else{
        q->rear = (q->rear+1) % q->size;
        q->ptr[q->rear] = data;
    }
}
struct Node *dequeue(struct Queue *q){
    struct Node *x = NULL;
    if(q->rear == q->front)
        printf("Queue is Empty\n");
    else{
        q->front = (q->front+1) % q->size;
        x = q->ptr[q->front];
    }
    return x;
}

struct Node *createTree(){
    struct Node *root, *last, *new;
    int x, input;
    struct Queue q;
    q = createQueue(100);

    printf("Enter Root: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    printf("Enter '1' to enter more childs or '0' to not: ");
    scanf("%d", &input);

    while(input){
        last = dequeue(&q);
        printf("Enter Left-Child: ");
        scanf("%d", &x);
        if(x!=-1){
            new = (struct Node *)malloc(sizeof(struct Node));
            new->data = x;
            new->lchild = new->rchild = NULL;
            last->lchild = new;
            enqueue(&q, new);
        }
        printf("Enter Right-Child: ");
        scanf("%d", &x);
        if(x!=-1){
            new = (struct Node *)malloc(sizeof(struct Node));
            new->data = x;
            new->lchild = new->rchild = NULL;
            last->rchild = new;
            enqueue(&q, new);
        }
        printf("Enter '1' to enter more childs or '0' to not: ");
        scanf("%d", &input);
    }
    return root;
}

void displayLevelorder(struct Node *root){
    struct Queue q = createQueue(100);
    enqueue(&q, root);
    while(q.front!=q.rear){
        root = dequeue(&q);
        printf("%d ", root->data);
        if(root->lchild)
            enqueue(&q, root->lchild);
        if(root->rchild)
            enqueue(&q, root->rchild);
    }
}

int countNodes(struct Node *root){
    if(root!=0){
        int x = countNodes(root->lchild);
        int y = countNodes(root->rchild);
        return x+y+1;
    }
    return 0;
}

int sum(struct Node *root){
    if(root!=0){
        int x = sum(root->lchild);
        int y = sum(root->rchild);
        return x + y + root->data;
    }
    return 0;
}

int height(struct Node *root){
    if(root!=0){
        int x = height(root->lchild);
        int y = height(root->rchild);
        if(x > y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

void main(){
    struct Node *root = createTree();
    printf("\nLevel-order: ");
    displayLevelorder(root);
    printf("\nNumber of nodes: %d", countNodes(root));
    printf("\nSum of nodes: %d", sum(root));
    printf("\nHeight of Tree: %d", height(root));
}