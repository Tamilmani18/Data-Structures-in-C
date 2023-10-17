#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct mystack{
    int data;
    struct mystack* next;
};

typedef struct mystack node;

node* top=NULL;

void push(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=val;
    newNode->next=top;
    top=newNode;
}

int pop(){
    node* del=top;
    if(top==NULL){
        printf("Stack is empty");
        return INT_MIN;
    }
    top=top->next;
    int temp=del->data;
    free(del);
    return temp;
}

int isEmpty() {
    return (top == NULL);
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack Elements: ");
        node* temp = top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int peek(){
    if(top==NULL){
        printf("Stack is empty");
        return INT_MIN;
    }
    return top->data;
}

int main(){
    int val;
    push(1);
    push(2);
    push(3);
    printf("Is the stack empty? %s\n", isEmpty() ? "Yes" : "No");
    display();
    printf("Popped %d\n",pop());
    printf("Top Element %d",peek());
    return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct mystack{
    int data;
    struct mystack* next;
};

typedef struct mystack node;

node* top=NULL;

void push(node **top,int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=val;
    newNode->next=*top;
    *top=newNode;
}

int pop(node **top){
    node* del=*top;
    if(*top==NULL){
        printf("Stack is empty");
        return INT_MIN;
    }
    *top=*top->next;
    int temp=del->data;
    free(del);
    return temp;
}

int peek(node **top){
    if(*top==NULL){
        printf("Stack is empty");
        return INT_MIN;
    }
    return *top->data;
}

int main(){
    node* top=NULL;
    push(&top,1);
    push(&top,2);
    push(&top,3);
    printf("Popped %d\n",pop(&top));
    printf("Top Element %d",peek(&top));
    return 0;
}

*/