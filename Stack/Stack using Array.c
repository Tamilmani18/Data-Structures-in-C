#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct mystack {
    int* arr;
    int top;
    int capacity;
};

typedef struct mystack stack;

stack* createStack(int capacity) {
    stack* s = (stack*)malloc(sizeof(stack));
    s->top = -1;
    s->capacity = capacity;
    s->arr = (int*)malloc(capacity * sizeof(int));
    return s;
}

void push(stack* s, int val) {
    if (s->top == s->capacity - 1) {
        s->capacity *= 2;
        s->arr = (int*)realloc(s->arr, s->capacity * sizeof(int));
    }
    s->arr[++s->top] = val;
}

int pop(stack* s) {
    if (s->top == -1) {
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    return s->arr[s->top--];
}

int peek(stack* s) {
    if (s->top == -1) {
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    return s->arr[s->top];
}

int isFull(stack* s) {
    return (s->top == s->capacity - 1);
}

int isEmpty(stack* s) {
    return (s->top == -1);
}

void display(stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack Elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    stack* s = createStack(10);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    printf("Is the stack full? %s\n", isFull(s) ? "Yes" : "No");
    printf("Is the stack empty? %s\n", isEmpty(s) ? "Yes" : "No");
    display(s);
    printf("Popped %d\n", pop(s));
    printf("Value %d\n", peek(s));
    free(s->arr);
    free(s);
    return 0;
}