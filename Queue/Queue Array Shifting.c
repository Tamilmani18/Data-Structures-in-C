#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 10

struct myQueue {
    int arr[MAX_SIZE];
    int rear;
};

typedef struct myQueue queue;

queue* createQueue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->rear = -1;
    return q;
}

void enqueue(queue* q, int val) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is Full\n");
        return;
    }
    q->arr[++(q->rear)] = val;
}

int dequeue(queue* q) {
    if(q->rear==-1){
        printf("Queue is Empty");
        return INT_MIN;
    }
    int temp= q->arr[0];
    for(int i=1;i< q->rear;i++){
        q->arr[i-1]=q->arr[i];
    }
    q->rear--;
    return temp;
}

int elementAtFirst(queue* q){
    if(q->rear==-1){
        printf("Queue is Empty");
        return INT_MIN;
    }
    return q->arr[0];
}

int isEmpty(queue* q){
    if(q->rear==-1){
        printf("Queue is Empty");
        return 1;
    }
    return 0;
}

int main() {
    queue* q1 = createQueue();
    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);
    enqueue(q1, 4);
    enqueue(q1, 5);
    printf("Dequeued %d\n", dequeue(q1));
    printf("Dequeued %d\n", dequeue(q1));
    printf("Dequeued %d\n", dequeue(q1));
    printf("Element at First : %d\n",elementAtFirst(q1));
    printf("%d",isEmpty(q1));
    return 0;
}