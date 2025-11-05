//  Given a sorted doubly linked list, design an algorithm and write a program to eliminate
//  duplicates from this list.

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head=NULL;
struct Node* createNode(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void insertEnd(int val){
    struct Node* newNode=createNode(val);
    if(head==NULL){head=newNode;return;}
    struct Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}
void display(struct Node* start){
    struct Node* temp=start;
    if(temp==NULL){printf("Doubly Linked List is empty\n");return;}
    while(temp!=NULL){printf("%d ",temp->data);temp=temp->next;}
    printf("\n");
}
void removeDuplicates(){
    if(head==NULL) return;
    struct Node* current=head;
    while(current!=NULL && current->next!=NULL){
        if(current->data==current->next->data){
            struct Node* dup=current->next;
            current->next=dup->next;
            if(dup->next!=NULL) dup->next->prev=current;
            free(dup);
        } else current=current->next;
    }
}
int main(){
    int choice,val;
    printf("Press:\n1 to insert element to linked list\n2 to exit\n");
    do{
        scanf("%d",&choice);
        switch(choice){
            case 1:scanf("%d",&val);insertEnd(val);break;
        }
    }while(choice!=2);
    printf("Doubly Linked List : ");
    display(head);
    removeDuplicates();
    printf("Doubly Linked List after duplicate removal : ");
    display(head);
    return 0;
}

