//  Write an algorithm and a program to implement doubly linked list. The program should
//  implement following operations:
//  a)Create(k) - create a doubly linked list node with value k.
//  b)InsertFront(k) - insert node at the front of the linked list.
//  c)InsertEnd(k) - insert a node at the end of the linked list.
//  d)InsertIntermediate(k,p) - insert a node at specific position p.
//  e)DeleteFront() - delete a node from the front of the linked list.
//  f)DeleteEnd() - delete a node from the end of the linked list.
//  g)DeleteIntermediate(p) – delete a node from a specific position p.
//  h)Size() - returns the size of doubly linked list.
//  i) IsEmpty() - checks whether the list is empty or not.
//  j) FindMiddle() - returns the contents of middle node of the list.

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
int isEmpty(){return head==NULL;}
int size(){
    int count=0;
    struct Node* temp=head;
    while(temp!=NULL){count++;temp=temp->next;}
    return count;
}
void insertFront(int val){
    struct Node* newNode=createNode(val);
    if(head==NULL){head=newNode;return;}
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}
void insertEnd(int val){
    struct Node* newNode=createNode(val);
    if(head==NULL){head=newNode;return;}
    struct Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}
void insertIntermediate(int pos,int val){
    if(pos==1){insertFront(val);return;}
    struct Node* newNode=createNode(val);
    struct Node* temp=head;
    for(int i=1;i<pos-1&&temp!=NULL;i++) temp=temp->next;
    if(temp==NULL) return;
    newNode->next=temp->next;
    if(temp->next!=NULL) temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}
void deleteFront(){
    if(head==NULL)return;
    struct Node* temp=head;
    printf("Node deleted - %d\n",temp->data);
    head=head->next;
    if(head!=NULL) head->prev=NULL;
    free(temp);
}
void deleteEnd(){
    if(head==NULL)return;
    struct Node* temp=head;
    if(temp->next==NULL){printf("Node deleted - %d\n",temp->data);free(temp);head=NULL;return;}
    while(temp->next!=NULL) temp=temp->next;
    printf("Node deleted - %d\n",temp->data);
    temp->prev->next=NULL;
    free(temp);
}
void deleteIntermediate(int pos){
    if(head==NULL||pos<1)return;
    if(pos==1){deleteFront();return;}
    struct Node* temp=head;
    for(int i=1;i<pos&&temp!=NULL;i++) temp=temp->next;
    if(temp==NULL) return;
    printf("Node deleted - %d\n",temp->data);
    if(temp->next!=NULL) temp->next->prev=temp->prev;
    if(temp->prev!=NULL) temp->prev->next=temp->next;
    free(temp);
}
void findMiddle(){
    if(head==NULL){printf("List is empty\n");return;}
    struct Node* slow=head;
    struct Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){slow=slow->next;fast=fast->next->next;}
    printf("Middle element: %d\n",slow->data);
}
void display(){
    if(head==NULL){printf("Doubly Linked List is empty\n");return;}
    struct Node* temp=head;
    printf("Doubly Linked List - ");
    while(temp!=NULL){printf("%d ",temp->data);temp=temp->next;}
    printf("\n");
}

int main(){
    int choice,val,pos;
    printf("Press:\n1 insert node at front\n2 insert node at end\n3 insert node at specific position\n4 delete node from front\n5 delete node from end\n6 delete node from specific position\n7 find size of linked list\n8 find middle element of the list\n9 exit\n");
    do{
        scanf("%d",&choice);
        switch(choice){
            case 1:scanf("%d",&val);insertFront(val);display();break;
            case 2:scanf("%d",&val);insertEnd(val);display();break;
            case 3:scanf("%d%d",&pos,&val);insertIntermediate(pos,val);display();break;
            case 4:deleteFront();display();break;
            case 5:deleteEnd();display();break;
            case 6:scanf("%d",&pos);deleteIntermediate(pos);display();break;
            case 7:printf("Size = %d\n",size());break;
            case 8:findMiddle();break;
        }
    }while(choice!=9);
    return 0;
}
