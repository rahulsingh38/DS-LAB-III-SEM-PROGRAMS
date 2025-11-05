//  Design an algorithm to implement binary trees. Write a program which implements following
//  basic operations on binary tree:
//  a) CreateTree() - creates a root node
//  b) InsertNode() - insert a node in tree
//  c) DeleteNode() - delete a node from tree
//  d) FindHeight() - find the height of tree
//  e) FindSize() - find number of nodes in tree
//  f) Search() - search whether given specific element present in tree or not.

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int val){
    if(val==-1) return NULL;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node* createTreeFromArray(int arr[], int n, int i){
    if(i>=n || arr[i]==-1) return NULL;
    struct Node* root=createNode(arr[i]);
    root->left=createTreeFromArray(arr,n,2*i+1);
    root->right=createTreeFromArray(arr,n,2*i+2);
    return root;
}
void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int findHeight(struct Node* root){
    if(root==NULL) return 0;
    int lh=findHeight(root->left);
    int rh=findHeight(root->right);
    return (lh>rh?lh:rh)+1;
}
int findSize(struct Node* root){
    if(root==NULL) return 0;
    return 1+findSize(root->left)+findSize(root->right);
}
int searchNode(struct Node* root, int key){
    if(root==NULL) return 0;
    if(root->data==key) return 1;
    return searchNode(root->left,key) || searchNode(root->right,key);
}
void insertNode(struct Node* root,int val){
    struct Node* newNode=createNode(val);
    if(root==NULL) {root=newNode; return;}
    struct Node* queue[100]; int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        struct Node* temp=queue[front++];
        if(temp->left) queue[rear++]=temp->left;
        else {temp->left=newNode; return;}
        if(temp->right) queue[rear++]=temp->right;
        else {temp->right=newNode; return;}
    }
}
void deleteNode(struct Node* root,int val){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        if(root->data==val){free(root); root=NULL;}
        return;
    }
    struct Node* queue[100]; int front=0,rear=0;
    queue[rear++]=root;
    struct Node* keyNode=NULL; struct Node* temp=NULL;
    while(front<rear){
        temp=queue[front++];
        if(temp->data==val) keyNode=temp;
        if(temp->left) queue[rear++]=temp->left;
        if(temp->right) queue[rear++]=temp->right;
    }
    if(keyNode){
        int x=temp->data;
        keyNode->data=x;
        front=0; rear=0; queue[rear++]=root;
        while(front<rear){
            temp=queue[front++];
            if(temp->left){
                if(temp->left->data==x){free(temp->left); temp->left=NULL; break;}
                else queue[rear++]=temp->left;
            }
            if(temp->right){
                if(temp->right->data==x){free(temp->right); temp->right=NULL; break;}
                else queue[rear++]=temp->right;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    struct Node* root=createTreeFromArray(arr,n,0);
    int choice,val;
    printf("Press:\n1 to insert a node\n2 to delete a node\n3 to exit\n");
    do{
        scanf("%d",&choice);
        switch(choice){
            case 1: scanf("%d",&val); insertNode(root,val); break;
            case 2: scanf("%d",&val); deleteNode(root,val); break;
        }
    }while(choice!=3);
    printf("Tree: ");
    inorder(root);
    printf("\n");
    printf("Height = %d\n", findHeight(root));
    printf("Size = %d\n", findSize(root));
    return 0;
}


