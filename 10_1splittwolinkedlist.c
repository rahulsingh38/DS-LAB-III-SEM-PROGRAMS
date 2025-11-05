//  Write an algorithm that will split a linked list into two linked lists, so that successive nodes go to
//  different lists. Odd numbered nodes to the first list while even numbered nodes to the second list.

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
void splitOddEven(struct Node* head, struct Node** oddHead, struct Node** evenHead){
    if(head==NULL) return;
    struct Node *oddTail=NULL, *evenTail=NULL;
    int count=1;
    struct Node* temp=head;
    while(temp!=NULL){
        if(count%2!=0){ // odd position
            if(*oddHead==NULL){*oddHead=createNode(temp->data); oddTail=*oddHead;}
            else {oddTail->next=createNode(temp->data); oddTail=oddTail->next;}
        } else { // even position
            if(*evenHead==NULL){*evenHead=createNode(temp->data); evenTail=*evenHead;}
            else {evenTail->next=createNode(temp->data); evenTail=evenTail->next;}
        }
        temp=temp->next;
        count++;
    } }
int main(){
    int choice,val;
    printf("Press:\n1 to insert node\n2 to exit\n");
    do{
        scanf("%d",&choice);
        if(choice==1){scanf("%d",&val); insertEnd(val);}
    }while(choice!=2);
    struct Node* oddHead=NULL;
    struct Node* evenHead=NULL;
    display(head,"Original List");
    splitOddEven(head,&oddHead,&evenHead);
    display(oddHead,"Odd numbered nodes list");
    display(evenHead,"Even numbered nodes list");
    return 0;
}


