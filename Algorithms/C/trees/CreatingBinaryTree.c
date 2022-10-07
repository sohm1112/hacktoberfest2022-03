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

void displayPreorder(struct Node *root){
    if(root!=0){
        printf("%d ", root->data);
        displayPreorder(root->lchild);
        displayPreorder(root->rchild);
    }
}

void displayInorder(struct Node *root){
    if(root!=0){
        displayInorder(root->lchild);
        printf("%d ", root->data);
        displayInorder(root->rchild);
    }
}

void displayPostorder(struct Node *root){
    if(root!=0){
        displayPostorder(root->lchild);
        displayPostorder(root->rchild);
        printf("%d ", root->data);
    }
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

void main(){
    struct Node *root = createTree();
    printf("\nLevel-order: ");
    displayLevelorder(root);
    printf("\nPre-order: ");
    displayPreorder(root);
    printf("\nIn-order: ");
    displayInorder(root);
    printf("\nPost-order: ");
    displayPostorder(root);
}