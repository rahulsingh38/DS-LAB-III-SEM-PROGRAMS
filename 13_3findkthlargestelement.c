// Given a complete binary tree, design an algorithm and write a program to find Kth largest
// element in it. (Hint: Max heap)

#include<stdio.h>
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;
    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
void buildMaxHeap(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
}
int extractMax(int arr[], int *n){
    int max = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return max;
}
int main(){
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    scanf("%d", &k);
    buildMaxHeap(arr, n);
    int tempN = n, kth;
    for(int i=0; i<k; i++) kth = extractMax(arr, &tempN);
    printf("K = %d, largest element : %d\n", k, kth);
    return 0;
}
