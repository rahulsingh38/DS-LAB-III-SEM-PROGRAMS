//  Design an algorithm and a program to convert binary search tree created in previous question into
//  balanced BST. Also find maximum and minimum element from this balanced BST.

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node* insertBST(struct Node* root,int val){
    if(root==NULL) return createNode(val);
    if(val<root->data) root->left=insertBST(root->left,val);
    else if(val>root->data) root->right=insertBST(root->right,val);
    return root;
}
void inorderTraversal(struct Node* root,int arr[],int* index){
    if(root==NULL) return;
    inorderTraversal(root->left,arr,index);
    arr[(*index)++]=root->data;
    inorderTraversal(root->right,arr,index);
}
struct Node* buildBalancedBST(int arr[],int start,int end){
    if(start>end) return NULL;
    int mid=(start+end)/2;
    struct Node* root=createNode(arr[mid]);
    root->left=buildBalancedBST(arr,start,mid-1);
    root->right=buildBalancedBST(arr,mid+1,end);
    return root;
}
void levelOrder(struct Node* root){
    if(root==NULL) return;
    struct Node* queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        struct Node* curr=queue[front++];
        printf("%d ",curr->data);
        if(curr->left) queue[rear++]=curr->left;
        if(curr->right) queue[rear++]=curr->right;
    }
    printf("\n");  }
int findMax(struct Node* root){
    while(root->right) root=root->right;
    return root->data;  }
int findMin(struct Node* root){
    while(root->left) root=root->left;
    return root->data;
}
int main(){
    int n,val;
    struct Node* root=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        if(val!=-1) root=insertBST(root,val);
    }
    printf("Initial BST: "); levelOrder(root);
    int arr[100]; int index=0;
    inorderTraversal(root,arr,&index);
    struct Node* balancedRoot=buildBalancedBST(arr,0,index-1);
    printf("Balanced BST: "); levelOrder(balancedRoot);
    printf("Maximum element: %d\n", findMax(balancedRoot));
    printf("Minimum element: %d\n", findMin(balancedRoot));
    return 0;
}

