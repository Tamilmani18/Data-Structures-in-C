#include <stdio.h>
#include <stdlib.h>

struct mynode {
    int data;
    struct mynode* next;
    struct mynode* prev;
};

typedef struct mynode node;

node* head = NULL;
node* tail = NULL;

void insertAtEnd(int val) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        newNode->prev = NULL;
        tail=newNode;
        return;
    }
    else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev=temp;
        tail=newNode;
    }
    printf("Inserted %d at the end",val);
}

void insertAtBeginning(int val) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = head;
    if (head == NULL) {
        tail = newNode;
    } 
    else {
        head->prev=newNode;
    }
    head = newNode;
    newNode->prev=NULL;
    printf("Inserted %d at the beginning",val);
}

void insertAtPos(int pos,int val){
    if (pos < 0) {
        printf("Invalid position: position cannot be negative\n");
        return;
    }
    if(pos==0){
        insertAtBeginning(val);
        return;
    } 
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=val;
    node* temp=head;
    if(head==NULL){
        printf("The list is empty\n");
        free(newNode);
        return;
    }
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
        if(temp==NULL){
            printf("Invalid position\n");
            return;
        }
    }
    newNode->next=temp->next;
    if(temp->next==NULL){
        tail = newNode;
    }
    else{
        temp->next->prev=newNode;
    }   
    temp->next=newNode;
    newNode->prev=temp;
    printf("Inserted %d at pos %d",val,pos);
}

void deleteAtPos(int pos){
    node* temp=head;
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    if (pos < 0) {
        printf("Invalid position: position cannot be negative\n");
        return;
    }
    if(pos==0){
        head=head->next;
        head->prev=NULL;
        printf("Deleted %d",temp->data);
        free(temp);
        return;
    }
    for(int i=0;i<pos;i++){
        temp=temp->next;
        if(temp==NULL){
            printf("Invalid position\n");
            return;
        }
    }
    temp->prev->next=temp->next;
    if(temp->next==NULL){
        tail=temp->prev;
    }
    else{
        temp->next->prev=temp->prev;
    }
    printf("Deleted %d",temp->data);
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void revDisplay() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    node* temp = tail;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void search(int val){
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    node* temp=head;
    int pos=1;
    while(temp!=NULL){
            if(temp->data==val){
                printf("The element %d found at position %d",val,pos);
                return;
            }
        temp=temp->next;
        pos++;
    }
    printf("Element %d not found in the list\n", val);
}

int main() {
    int choice, val, pos;
    while (1) {
        printf("\t\t\tLinked List Operations\n");
        printf("1. Insert at End\n");
        printf("2. Insert at Beginning\n");
        printf("3. Display\n");
        printf("4. Insert at specific position\n");
        printf("5. Delete at specific position\n");
        printf("6. Search\n");
        printf("7. Reverse\n");
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
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;
            case 6:
                printf("Enter the value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 7:
                revDisplay();
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