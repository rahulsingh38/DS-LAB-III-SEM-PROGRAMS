//  Given a linked list and a number n, design an algorithm and write a program to find the value at
//  the n'th node from end of this linked list.

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
int findNthFromEnd(struct Node* head, int n){
    struct Node* first=head;
    struct Node* second=head;
    for(int i=0;i<n;i++){
        if(first==NULL) return -1; // n is larger than length
        first=first->next;
    }
    while(first!=NULL){
        first=first->next;
        second=second->next;
    }
    return second->data;
}
int main(){
    int choice,val,n;
    printf("Press:\n1 to insert node\n2 to exit\n");
    do{
        scanf("%d",&choice);
        if(choice==1){scanf("%d",&val); insertEnd(val);}
    }while(choice!=2);
    display(head,"Linked List");
    printf("Enter value n: ");
    scanf("%d",&n);
    int res=findNthFromEnd(head,n);
    if(res!=-1) printf("Value at position %d from end : %d\n", n, res);
    else printf("Invalid n, list is shorter than %d nodes\n", n);
    return 0;
}
