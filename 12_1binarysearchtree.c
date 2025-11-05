//  Design an algorithm and a program to implement binary search tree. The program should
//  implement following BST operations:
//  a) Create() - creates a root node.
//  b) Insert() - insert a node in tree.
//  c) Delete() - delete a node from tree.
//  d) FindHeight() - return height of tree.
//  e) FindDepth() - return depth of tree.
//  f) Search() - search whether given key is present in tree or not.


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

struct Node* findMin(struct Node* root){
    while(root->left!=NULL) root=root->left;
    return root;
}
struct Node* deleteBST(struct Node* root,int val){
    if(root==NULL) return root;
    if(val<root->data) root->left=deleteBST(root->left,val);
    else if(val>root->data) root->right=deleteBST(root->right,val);
    else{
        if(root->left==NULL){
            struct Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct Node* temp=root->left;
            free(root);
            return temp;
        }
        struct Node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteBST(root->right,temp->data);
    }
    return root;
}
int height(struct Node* root){
    if(root==NULL) return 0;
    int l=height(root->left);
    int r=height(root->right);
    return (l>r?l:r)+1;
}
int depth(struct Node* root){
    return height(root);
}
int searchBST(struct Node* root,int key){
    if(root==NULL) return 0;
    if(root->data==key) return 1;
    if(key<root->data) return searchBST(root->left,key);
    else return searchBST(root->right,key);
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
    printf("\n");
}
int main(){
    int n,val,choice,key;
    struct Node* root=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        if(val!=-1) root=insertBST(root,val);
    }
    printf("Press:\n1 to insert a node\n2 to delete a node\n3 to search a key\n4 to exit\n");
    do{
        scanf("%d",&choice);
        switch(choice){
            case 1: scanf("%d",&val); root=insertBST(root,val); break;
            case 2: scanf("%d",&val); root=deleteBST(root,val); break;
            case 3: printf("Enter key: "); scanf("%d",&key);
                    printf(searchBST(root,key)?"%d - present\n":"Not present\n",key);
                    break;
        }
    }while(choice!=4);
    printf("BST: "); levelOrder(root);
    printf("Height = %d\n",height(root));
    printf("Depth = %d\n",depth(root));
    return 0;
}


