//  Given a binary tree, design an algorithm and write a program to check whether this tree is heap or
//  not. Tree should satisfy following heap properties:
//  a) Tree should be complete binary tree
//  b)Every nodes value should be greater than or equal to its child node (incase of max heap)

#include<stdio.h>
int isHeap(int arr[], int n){
    for(int i=0; i<= (n-2)/2; i++){
        if(arr[i] < arr[2*i+1]) return 0;
        if(2*i+2 < n && arr[i] < arr[2*i+2]) return 0;
    }
    return 1;
}
int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int arr[n];
        for(int i=0; i<n; i++) scanf("%d", &arr[i]);
        if(isHeap(arr, n)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
