// Given a binary search tree, design an algorithm and write a program to find which level number
//  of tree has maximum number of nodes. Also print maximum number of nodes present at this
//  level.

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
void levelOrder(struct Node* root,int levels[],int* maxLevel){
    if(root==NULL) return;
    struct Node* queue[100];
    int front=0,rear=0;
    int levelQueue[100];
    queue[rear]=root;
    levelQueue[rear++]=1;
    printf("BST: ");
    while(front<rear){
        struct Node* curr=queue[front];
        int lvl=levelQueue[front++];
        printf("%d ",curr->data);
        levels[lvl-1]++;
        if(curr->left){queue[rear]=curr->left; levelQueue[rear++]=lvl+1;}
        if(curr->right){queue[rear]=curr->right; levelQueue[rear++]=lvl+1;}
        if(lvl>*maxLevel) *maxLevel=lvl;
    }
    printf("\n");
}
int main(){
    int n,val;
    struct Node* root=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        if(val!=-1) root=insertBST(root,val);
    }
    int levels[100]={0};
    int maxLevel=0;
    levelOrder(root,levels,&maxLevel);
    int maxNodes=0,levelNum=0,equal=1;
    for(int i=0;i<maxLevel;i++){
        if(levels[i]>maxNodes){maxNodes=levels[i]; levelNum=i+1;}
    }
    for(int i=0;i<maxLevel;i++){
        if(levels[i]!=maxNodes){equal=0; break;}
    }
    if(equal) printf("Equal no. Of nodes on all levels\n");
    else printf("Level %d has %d nodes\n",levelNum,maxNodes);
    return 0;
}



