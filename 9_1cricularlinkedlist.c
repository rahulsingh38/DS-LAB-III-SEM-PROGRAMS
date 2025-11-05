//  Design an algorithm and write a program to implement circular linked list. The program should
//  implement following operations:
//  a) Create(k) - creates a circular linked list node with value k.
//  b)InsertFront() - insert node at the front of list.
//  c) InsertEnd() - insert node at the end of list.
//  d)InsertIntermediate() - insert node at any specified position of list.
//  e) DeleteFront() - delete node from the front of list.
//  f) DeleteEnd() - delete node from the end of list.
//  g)DeleteIntermediate() - delete node from any specified position of list.
//  h)Size() - return size of circular linked list.
//  i)  IsEmpty() - checks whether list is empty or not.

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
    newNode->next=newNode;
    return newNode;
}
int isEmpty(){
    return head==NULL;
}
int size(){
    if(isEmpty()) return 0;
    int count=1;
    struct Node* temp=head;
    while(temp->next!=head){count++; temp=temp->next;}
    return count;
}
void insertFront(int val){
    struct Node* newNode=createNode(val);
    if(head==NULL){head=newNode; return;}
    struct Node* temp=head;
    while(temp->next!=head) temp=temp->next;
    newNode->next=head;
    temp->next=newNode;
    head=newNode;
}
void insertEnd(int val){
    struct Node* newNode=createNode(val);
    if(head==NULL){head=newNode; return;}
    struct Node* temp=head;
    while(temp->next!=head) temp=temp->next;
    temp->next=newNode;
    newNode->next=head;
}
void insertIntermediate(int pos,int val){
    if(pos==1){insertFront(val); return;}
    int n=size();
    if(pos>n+1) return;
    struct Node* newNode=createNode(val);
    struct Node* temp=head;
    for(int i=1;i<pos-1;i++) temp=temp->next;
    newNode->next=temp->next;
    temp->next=newNode;
}
void deleteFront(){
    if(isEmpty()) return;
    struct Node* temp=head;
    if(head->next==head){free(head); head=NULL; return;}
    struct Node* last=head;
    while(last->next!=head) last=last->next;
    head=head->next;
    last->next=head;
    printf("Node deleted - %d\n", temp->data);
    free(temp);
}
void deleteEnd(){
    if(isEmpty()) return;
    struct Node* temp=head;
    if(head->next==head){printf("Node deleted - %d\n",head->data); free(head); head=NULL; return;}
    while(temp->next->next!=head) temp=temp->next;
    struct Node* last=temp->next;
    temp->next=head;
    printf("Node deleted - %d\n", last->data);
    free(last);
}
void deleteIntermediate(int pos){
    if(isEmpty() || pos<1) return;
    if(pos==1){deleteFront(); return;}
    int n=size();
    if(pos>n) return;
    struct Node* temp=head;
    for(int i=1;i<pos-1;i++) temp=temp->next;
    struct Node* del=temp->next;
    temp->next=del->next;
    printf("Node deleted - %d\n", del->data);
    free(del);
}
void display(){
    if(isEmpty()){printf("Circular Linked List is empty\n"); return;}
    struct Node* temp=head;
    printf("Circular Linked List : ");
    do{printf("%d ",temp->data); temp=temp->next;}while(temp!=head);
    printf("\n");
}
int main(){
    int choice, val, pos;
    printf("Press:\n1 insert front\n2 insert end\n3 insert at position\n4 delete front\n5 delete end\n6 delete at position\n7 size\n8 isEmpty\n9 display\n10 exit\n");
    do{
       scanf("%d",&choice);
        switch(choice){
            case 1: scanf("%d",&val); insertFront(val); display(); break;
            case 2: scanf("%d",&val); insertEnd(val); display(); break;
            case 3: scanf("%d%d",&pos,&val); insertIntermediate(pos,val); display(); break;
            case 4: deleteFront(); display(); break;
            case 5: deleteEnd(); display(); break;
            case 6: scanf("%d",&pos); deleteIntermediate(pos); display(); break;
            case 7: printf("Size = %d\n", size()); break;
            case 8: printf(isEmpty()?"List is empty\n":"List is not empty\n"); break;
            case 9: display(); break;
        }
    }while(choice!=10);
    return 0;
}
