#include <stdio.h>
#include <stdlib.h>

struct mynode {
    int data;
    struct mynode* next;
};

typedef struct mynode node;

node* head = NULL;

void insertAtEnd(int val) {
    node* newNode = (node*)malloc(sizeof(node));  //converting void pointer into node pointer
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end",val);
}

void insertAtBeginning(int val) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } 
    else {
        newNode->next = head;
        head = newNode;
    }
    printf("Inserted %d at the beginning",val);
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
    temp->next=newNode;
    printf("Inserted %d at pos %d",val,pos);
}

void deleteAtPos(int pos){
    node* temp=head;
    node* prev;
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
        printf("Deleted %d",temp->data);
        free(temp);
        return;
    }
    for(int i=0;i<pos;i++){
        prev=temp;
        temp=temp->next;
        if(temp==NULL){
            printf("Invalid position\n");
            return;
        }
    }
    prev->next=temp->next;
    printf("Deleted %d",temp->data);
    free(temp);
}

void delete(int val) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    node* temp = head;
    node* prev = NULL;
    if (head->data == val) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Element %d deleted from the list\n", val);
        return;
    }
    while (temp != NULL) {
        if (temp->data == val) {
            prev->next = temp->next;
            free(temp);
            printf("Element %d deleted from the list\n", val);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Element %d not found in the list\n", val);
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

void reverse(){
    node* prev=NULL;
    node* current=head;
    node* next=head->next;
    while (current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    } 
    head=prev; 
}

node* reversedelete(int pos) {
    node* prev = NULL;
    node* current = head;
    node* next = head->next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    if (head == NULL) {
        printf("The list is empty\n");
        return head;
    }
    if (pos < 0) {
        printf("Invalid position: position cannot be negative\n");
        return head;
    }
    if (pos == 0) {
        node* temp = head;
        head = head->next;
        printf("Deleted %d\n", temp->data);
        free(temp);
        return head;
    }
    node* temp = head;
    node* prev2 = head;

    for (int i = 0; i < pos; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return head;
        }
        prev2 = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }

    prev2->next = temp->next;
    printf("Deleted %d\n", temp->data);
    free(temp);
    return head;
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
        printf("8. Delete\n");
        printf("9. Exit\n");
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
                reverse();
                break;
            case 8:
                printf("Enter the val to delete: ");
                scanf("%d", &val);
                delete(val);
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}




