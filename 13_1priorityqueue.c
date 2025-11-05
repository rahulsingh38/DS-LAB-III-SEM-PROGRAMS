//  Write an algorithm and a program to implement priority queue (also known as heap). Priority
//  queue has following properties:
//  a) Each item has a priority associated with it. 
//  b) Element which has heighest priority is dequeued before an element with low priority.
//  c) If two elements have the same priority, they are served according to their order in the queue.
//  d) It is always in the form of complete tree.
//  e) Element which has highest priority should be at root, element which has priority less than
//     root but more than other elements comes at level 2. Hence as the level increases, priority of
//     element decreases.
//     The program should implement following operations:
//  a) create() - create root node of priority heap
//  b) insert() - insert an element into the priority queue. Everytime when a node is inserted, tree
//               should be balanced according to its priority.
//  c) getHighestPriority() - finds the element which has highest priority
//  d) deleteHeighestPriority() - delete the element which has highest priority



#include<stdio.h>
#include<stdlib.h>
int heap[100], n=0;
void swap(int *a,int *b){int t=*a; *a=*b; *b=t;}
void heapifyUp(int i){
    while(i!=0 && heap[(i-1)/2]<heap[i]){
        swap(&heap[i], &heap[(i-1)/2]);
        i=(i-1)/2;
    }
}
void heapifyDown(int i){
    int largest=i;
    int l=2*i+1, r=2*i+2;
    if(l<n && heap[l]>heap[largest]) largest=l;
    if(r<n && heap[r]>heap[largest]) largest=r;
    if(largest!=i){
        swap(&heap[i], &heap[largest]);
        heapifyDown(largest);
    }
}
void insert(int val){
    heap[n]=val;
    n++;
    heapifyUp(n-1);
}
int getHighestPriority(){ return heap[0]; }
void deleteHighestPriority(){
    if(n==0) return;
    printf("Deleted element with highest priority: %d\n", heap[0]);
    heap[0]=heap[n-1];
    n--;
    heapifyDown(0);
}
void display(){
    printf("Priority Queue: ");
    for(int i=0;i<n;i++) printf("%d ",heap[i]);
    printf("\n");
}
int main(){
    int size, val, choice;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d",&val);
        insert(val);
    }
    printf("Initial Priority Queue: ");
    display();
    printf("Max Priority: %d\n", getHighestPriority());
    printf("Press:\n1 to insert node\n2 to delete node\n3 to exit\n");
    do{
        scanf("%d",&choice);
        switch(choice){
            case 1: scanf("%d",&val); insert(val); printf("Updated Priority Queue: "); display(); break;
            case 2: deleteHighestPriority(); printf("Updated Priority Queue: "); display(); break;
        }
    } while(choice!=3);
    return 0;  }

