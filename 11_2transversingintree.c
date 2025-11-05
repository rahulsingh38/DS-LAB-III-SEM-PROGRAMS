//  Write an algorithm and a program to implement following types of traversing in the tree:
//  a) inorder() - (1) traverse left subtree, (2) traverse root, (3) traverse right subtree
//  b) postorder() - (1) traverse root, (2) traverse left subtree, (3) traverse right subtree
//  c) preorder() - (1) traverse left subtree, (2) traverse right subtree, (3) traverse root

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
void postorder(struct Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void preorder(struct Node* root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    struct Node* root=createTreeFromArray(arr,n,0);
    printf("Inorder : ");
    inorder(root);
    printf("\n");
    printf("Postorder : ");
    postorder(root);
    printf("\n");
    printf("Preorder : ");
    preorder(root);
    printf("\n");
    return 0;
}
