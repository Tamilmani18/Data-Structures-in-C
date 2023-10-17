#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct mynode {
    int data;
    struct mynode* next;
};

typedef struct mynode node;

struct  Queue{
    node* front;
    node* rear;
};

//different front and rear for different queue
struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}

void enQueue(struct  Queue* q,int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=val;
    newNode->next=NULL;
    if(q->front==NULL)
        q->front=newNode;
    else
        q->rear->next=newNode;

    q->rear=newNode;

    printf("Enqueued %d",val);
}

int deQueue(struct  Queue* q){
    if(q->front==NULL){
        printf("Queue is Empty");
        return INT_MIN;
    }
    else{
        node* del = q->front;
        q->front=q->front->next;
        if(q->front==NULL)
            q->rear=NULL;
        int temp=del->data;
        free(del);
        return temp;
    }
}

int isEmpty(struct  Queue* q){
     if(q->front==NULL){
        return 1;
    }
    return 0;
}


void display(struct Queue* q) {
    node* temp = q->front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    struct  Queue* q1 = createQueue();
    
    return 0;
}