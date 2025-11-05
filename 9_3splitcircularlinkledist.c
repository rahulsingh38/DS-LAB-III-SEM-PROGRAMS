//  Write an algorithm and a program that will split a circularly linked list into two circularly linked
//  list provided position from where circular linked list has to be splitted.

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
void insertEnd(int val){
    struct Node* newNode=createNode(val);
    if(head==NULL){head=newNode; return;}
    struct Node* temp=head;
    while(temp->next!=head) temp=temp->next;
    temp->next=newNode;
    newNode->next=head;
}
void display(struct Node* h,const char* msg){
    if(h==NULL){printf("%s is empty\n",msg); return;}
    struct Node* temp=h;
    printf("%s : ", msg);
    do{printf("%d ", temp->data); temp=temp->next;}while(temp!=h);
    printf("\n");
}
void splitCircularList(int k, struct Node** first, struct Node** second){
    if(head==NULL || k<=0) return;
    struct Node* temp=head;
    int count=1;
    while(count<k && temp->next!=head){temp=temp->next; count++;}
    *first=head;
    *second=temp->next;
    temp->next=*first; // end first list
    struct Node* last=*second;
    while(last->next!=head) last=last->next;
    last->next=*second; // end second list
}
int main(){
    int choice,val,k;
    printf("Press:\n1 to insert\n2 to exit\n");
    do{
        scanf("%d",&choice);
        if(choice==1){scanf("%d",&val); insertEnd(val);}
    }while(choice!=2);
    printf("Enter position to split the list: ");
    scanf("%d",&k);
    struct Node* firstPart=NULL;
    struct Node* secondPart=NULL;
    display(head,"Original List");
    splitCircularList(k,&firstPart,&secondPart);
    display(firstPart,"First part of list");
    display(secondPart,"Second part of list");
    return 0;
}
