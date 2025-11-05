//  Given a doubly linked list, design an algorithm and write a program to reverse this list without
//  using any extra space.

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
void display(){
    struct Node* temp=head;
    if(temp==NULL){printf("Doubly Linked List is empty\n");return;}
    printf("Doubly Linked List : ");
    while(temp!=NULL){printf("%d ",temp->data);temp=temp->next;}
    printf("\n");
}
void reverseList(){
    struct Node* temp=NULL;
    struct Node* current=head;
    while(current!=NULL){
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    if(temp!=NULL) head=temp->prev;
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
    display();
    reverseList();
    printf("Reversed Doubly Linked List : ");
    struct Node* temp=head;
    while(temp!=NULL){printf("%d ",temp->data);temp=temp->next;}
    printf("\n");
    return 0;
}
