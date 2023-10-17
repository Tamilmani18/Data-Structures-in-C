#include<stdio.h>
#include<stdlib.h>

struct mynode{
    int data;
    struct mynode* next;
};

typedef struct mynode node;

node* last=NULL;

void insertAtBeginning(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=val;
    if(last==NULL){
        newNode->next=newNode;
        last=newNode;
    }
    else{
        newNode->next=last->next;
        last->next=newNode;
    }
    printf("\n");
}

void display(){
    node* temp=last->next;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=last->next);

    printf("\n");

}

void insertAtEnd(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=val;
    if(last==NULL){
        newNode->next=newNode;
        last=newNode;
    }
    else{
        newNode->next=last->next;
        last->next=newNode;
        last=newNode;
    }
    printf("\n");
}

void insertAtPos(int pos, int val) {
    if (last == NULL || pos <= 0) {
        printf("Invalid position or list is empty.\n");
        return;
    }

    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;

    if (pos == 1) {
        newNode->next = last->next;
        last->next = newNode;
    }
    else {
        node* current = last->next;
        int i = 1;
        while (i < pos - 1 && current != last) {
            current = current->next;
            i++;
        }

        if (i != pos - 1) {
            printf("Invalid position.\n");
            free(newNode);
        }
        else {
            newNode->next = current->next;
            current->next = newNode;
            if (current == last) {
                last = newNode;
            }
        }
    }
}

void deleteAtBeginning(){
    if(last==NULL){
        printf("List is empty");
        return;
    }
    node* temp=last->next;
    if(last->next==last){
        last=NULL;
        return;
    }
    else{
        last->next=temp->next;
    }
    free(temp);  
}

void deleteAtEnd(){
    if(last==NULL){
        printf("List is empty");
        return;
    }
    node* temp=last->next;
    node* del=last;
    if(last->next==last){
        last=NULL;
    }
    else{
        while(temp->next!=last){
        temp=temp->next;
    }
    temp->next=last->next; 
    last=temp;
    }
    free(del);
}

void delete(int val) {
    if (last == NULL || last->next == last) {
        printf("List is empty");
        return;
    }
    node* temp = last->next;
    node* prev = NULL;
    node* del = NULL;
    
    do {
        prev = temp;
        if (temp->data == val) {
            del = temp;
            prev->next = del->next;
            if (temp == last) {
                last = prev;
            }
            break;
        }
        temp = temp->next;
    } while (temp != last->next);
    
    if (del != NULL) {
        free(del);
    } else {
        printf("Value not found in the list.\n");
    }
}


int main(){
    int choice, val, pos;
    while (1) {
        printf("\t\t\tLinked List Operations\n");
        printf("1. Insert at End\n");
        printf("2. Insert at Beginning\n");
        printf("3. Display\n");
        printf("4. Insert at specific position\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete a Value\n");
        printf("8. Exit\n");
        printf("Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter your value: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 2:
                printf("Enter your value: ");
                scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                printf("Enter the Value: ");
                scanf("%d", &val);
                insertAtPos(pos, val);
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Enter the value to delete: ");
                scanf("%d", &val);
                delete(val);
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}