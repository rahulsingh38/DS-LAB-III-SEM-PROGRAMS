//  Given an unsorted array of integers and two numbers a and b. Design an algorithm and write a
//  program to find minimum distance between a and b in this array. Minimum distance between any
//  two numbers a and b present in array is the minimum difference between their indices.

#include<stdio.h>
#include<stdlib.h>
void main(){
    int n;
    printf("enter the size of the array...\n");
    scanf("%d",&n);
    int arr[n],i,a,b,ina,inb,d;
    printf("enter the elements:");
    for(i=0;i<n;i++)  {
        scanf("%d\t",&arr[i]);
    }
    printf("enter the two numbers \n");
    scanf("%d%d",&a,&b);
    int mind=n;
    ina=-1,inb=-1;
    for(i=0;i<n;i++){
        if(arr[i]==a) {
            ina=i;
        }
        if(arr[i]==b) {
            inb=i;
        }
        if(ina!=-1 && inb!=-1) {
        d=abs(ina-inb);
        }
        if(d<mind) {
            mind=d;}
    }
    printf("the distance between the index of %d and %d is %d", a,b,mind); 
 }
