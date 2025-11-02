//  Given an array of integers, write an algorithm and a program to left rotate the array by specific
//  number of elements.

#include<stdio.h>
#include<stdlib.h>
void main()
{
      int n;
      printf("enter the size of array\n");
      scanf("%d",&n);
      int i, arr[n];
      printf("enter integers\n");
      for(i=0;i<n;i++)
      {  scanf("%d",&arr[i]);
      }
      int temp,j,k;
      printf("enter the rotation time\n");
      fflush(stdout);                          
      scanf("%d",&k);
      k=k%n;
      for(j=0;j<k;j++)
      {  temp=arr[0];                          
          for(i=0;i<n;i++){                          
            arr[i]=arr[i+1];                    
          }
          arr[n-1]=temp;   }               
      printf("after rotation\n");
      for(i=0;i<n;i++) {
        printf("%d\t",arr[i]);  }
        return 0;
     }