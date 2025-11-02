// .Given a matrix of size n X n containing positive integers, write an algorithm and a program to
//  rotate the elements of matrix in clockwise direction.

#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,i,j;
    printf("enter the size of matrix\n");
    scanf("%d",&n);
    int a[n][n];
    printf("enter the elements of matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)  {
            scanf("%d",&a[i][j]);       
        }
    }
    int r=0 , c=0 , lr=n ,lc=n;
    int temp,cur;
     while(r<lr &&c<lc) {
            if(r+1==lr &&c+1==lc) {
                break;  }
            temp=a[r+1][c];
            for(i=c;i<lc;i++){
                cur=a[r][i];
                a[r][i]=temp;
                temp=cur;
            } 
r++;
            for(i=r;i<lr;i++)
            { cur=a[i][lc-1];
                a[i][lc-1]=temp;
                temp=cur;
            }
            lc--;
            for(i=lc-1;i>=c;i--)  {
                cur=a[lr-1][i];
                a[lr-1][i]=temp;
                temp=cur;
            }
            lr--;
            for(i=lr-1;i>=r;i--) {
                cur=a[i][c];
                a[i][c]=temp;
                temp=cur;
            }
            c++;    //18
        }
        printf("after rotation\n");
        for(i=0;i<n;i++)  {
            for(j=0;j<n;j++)  {
                printf("%d ", a[i][j]);     
            }
        }
}
