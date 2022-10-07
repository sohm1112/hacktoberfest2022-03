#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *lchild, *rchild;
};
struct Node *root = NULL;

void insert(int key){
    struct Node *curr = root, *prev, *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = key;
    new->lchild = new->rchild = NULL;
    if(root == NULL){
        root = new;
        return;
    }
    while(curr!=0){
        prev = curr;
        if(key < curr->data)
            curr = curr->lchild;
        else if(key > curr->data)
            curr = curr->rchild;
        else
            return;
    }
    if(key < prev->data)
        prev->lchild = new;
    else
        prev->rchild = new;
}

void displayInorder(struct Node *root){
    if(root!=0){
        displayInorder(root->lchild);
        printf("%d ", root->data);
        displayInorder(root->rchild);
    }
}

struct Node *search(int key){
    struct Node *p = root;
    while(p!=0){
        if(p->data > key)
            p = p->lchild;
        else if(p->data < key)
            p = p->rchild;
        else
            break;
    }
    return p;
}

struct Node *Rinsert(struct Node *p, int key){
    if(p==NULL){
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = Rinsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = Rinsert(p->rchild, key);
    return p;
}

int height(struct Node *p){
    if(p==NULL)
        return 0;
    else{
        int x = height(p->lchild);
        int y = height(p->rchild);
        return (x>y) ? x+1 : y+1;
    }
}

struct Node *InPre(struct Node *p){
    while(p && p->rchild)
        p = p->rchild;
    return p;
}

struct Node *InSucc(struct Node *p){
    while(p && p->lchild)
        p = p->lchild;
    return p;
}

struct Node *Rdelete(struct Node *p, int key){
    struct Node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild == NULL && p->rchild == NULL){
        if(p==root)
            root = NULL;
        free(p);
        return NULL;
    }
    if(key < p->data)
        p->lchild = Rdelete(p->lchild, key);
    else if(key > p->data)
        p->rchild = Rdelete(p->rchild, key);
    else{
        if(height(p->lchild) > height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Rdelete(p->lchild, q->data);
        }
        else{
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Rdelete(p->rchild, q->data);
        }
    }
    return p;
}

void main(){
    int arr[] = {9, 15, 5, 20, 16, 8, 12, 3, 6};
    int n = sizeof(arr)/sizeof(int);
    root = Rinsert(root, 9);
    for(int i=1; i<n; i++){
        Rinsert(root, arr[i]);
    }
    printf("\nInorder: ");
    displayInorder(root);

    struct Node *temp = search(20);
    if(temp!=0)
        printf("\nElement found at: %p\n", temp);
    else
        printf("\nElement not found\n");

    temp = Rdelete(root, 9);
    printf("\nInorder: ");
    displayInorder(root);
}