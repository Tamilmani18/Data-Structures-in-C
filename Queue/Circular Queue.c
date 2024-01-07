#include <stdio.h>

#define size 5

int arr[size];
int front = -1, rear = -1;

int isFull() {
    if (front==(rear+1)%size) return 1;
    return 0;
}

// Check if the queue is empty
int isEmpty() {
    if (front == -1 && rear==-1) return 1;
        return 0;
}

// Adding an val
void enQueue(int val) {
    if (isFull()){
        printf("\n Queue is full!! \n");
        return;
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
    }
    else{
        rear = (rear + 1) % size;
    }
    arr[rear] = val;
    printf("\n Inserted -> %d", val);
}

// Removing an val
int deQueue() {
    int val;
    if (isEmpty()) {
        printf("\n Queue is empty !! \n");
        return (-1);
    } 
    else if(front == rear) {
        printf("\n Deleted val -> %d \n", arr[front]);
        front = rear = -1;
    } 
    else{
        printf("\n Deleted val -> %d \n", arr[front]);
        front = (front + 1) % size;
    }
}

// Display the queue
void display() {
    if (isEmpty()) {
        printf("\n Queue is empty !! \n");
        return (-1);
    } 
    else {
        printf("\n Queue -> ");
        for (int i = front; i != rear; i = (i + 1) % size) {
            printf("\t%d", arr[i]);
        }
        printf("\t%d", arr[rear]);
    }
}

int main() {
  // Fails because front = -1
    deQueue();

    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);

  // Fails to enqueue because front == 0 && rear == size - 1
    enQueue(6);

    display();
    deQueue();

    display();

    enQueue(7);
    display();

  // Fails to enqueue because front == rear + 1
    enQueue(8);

    return 0;
}
