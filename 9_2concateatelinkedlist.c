// Design an algorithm and write a program to concatenate two circularly linked lists.

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head1=NULL;
struct Node* head2=NULL;
struct Node* createNode(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=newNode;
    return newNode;
}
void insertEnd(struct Node** head,int val){
    struct Node* newNode=createNode(val);
    if(*head==NULL){*head=newNode; return;}
    struct Node* temp=*head;
    while(temp->next!=*head) temp=temp->next;
    temp->next=newNode;
    newNode->next=*head;
}
void display(struct Node* head,const char* msg){
    if(head==NULL){printf("%s is empty\n", msg); return;}
    struct Node* temp=head;
    printf("%s : ", msg);
    do{printf("%d ", temp->data); temp=temp->next;}while(temp!=head);
    printf("\n");
}
void concatenate(struct Node** head1, struct Node** head2){
    if(*head1==NULL){*head1=*head2; return;}
    if(*head2==NULL) return;
    struct Node* temp1=*head1;
    while(temp1->next!=*head1) temp1=temp1->next;
    struct Node* temp2=*head2;
    while(temp2->next!=*head2) temp2=temp2->next;
    temp1->next=*head2;
    temp2->next=*head1;
}
int main(){
    int choice,val;
    printf("First circular linked list:\nPress:\n1 to insert node\n2 to exit\n");
    do{
        scanf("%d",&choice);
        if(choice==1){scanf("%d",&val); insertEnd(&head1,val);}
    }while(choice!=2);
    printf("Second circular linked list:\nPress:\n1 to insert node\n2 to exit\n");
    do{
        scanf("%d",&choice);
        if(choice==1){scanf("%d",&val); insertEnd(&head2,val);}
    }while(choice!=2);
    display(head1,"First circular linked list");
    display(head2,"Second circular linked list");
    concatenate(&head1,&head2);
    display(head1,"Final Concatenated linked list");
    return 0;
} 


