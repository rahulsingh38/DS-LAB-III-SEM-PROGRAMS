// .Write a program that will reverse a linked list only by traversing it once and without using  extra
//  space.

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
struct Node* createNode(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}
void insertEnd(int val){
    struct Node* newNode=createNode(val);
    if(head==NULL){head=newNode; return;}
    struct Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newNode;
}
void display(struct Node* h,const char* msg){
    if(h==NULL){printf("%s is empty\n",msg); return;}
    struct Node* temp=h;
    printf("%s : ", msg);
    while(temp!=NULL){printf("%d ", temp->data); temp=temp->next;}
    printf("\n");
}
void reverse(){
    struct Node *prev=NULL, *curr=head, *next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
int main(){
    int choice,val;
    printf("Press:\n1 to insert node\n2 to exit\n");
    do{
        scanf("%d",&choice);
        if(choice==1){scanf("%d",&val); insertEnd(val);}
    }while(choice!=2);
    display(head,"Original Linked List");

    reverse();
    display(head,"Reversed Linked List");
    return 0;
}

