#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 10

struct myQueue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

typedef struct myQueue queue;

queue* createQueue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(queue* q, int val) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is Full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->arr[++(q->rear)] = val;
}

int dequeue(queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is Empty\n");
        return INT_MIN;
    }
    int dequeuedValue = q->arr[q->front];
    q->front++;
    return dequeuedValue;
}

int isEmpty(queue* q){
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is Empty\n");
        return 1;
    }
    return 0;
}

int isFull(queue* q){
    if (q->rear == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}

int elementAtFirst(queue* q){
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is Empty\n");
        return INT_MIN;
    }
    return q->arr[q->front];
}

void display(queue* q){
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is Empty\n");
    }
    else{
        for(int i = q->front; i <= q->rear; i++){
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
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
    printf("%d\n",isEmpty(q1));
    printf("%d\n",isFull(q1));
    display(q1);
    return 0;
}