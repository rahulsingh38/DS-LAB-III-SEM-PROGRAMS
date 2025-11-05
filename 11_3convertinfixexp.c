// For an expression in the form of binary tree, infix representation of the expression is given in the
//  form of character array.. Design an algorithm and a program to convert infix expression of this
//  tree to postfix expression. Postfix representation of expression should follow BODMAS rule.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int precedence(char op){
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}
void infixToPostfix(char* exp){
    char stack[100];
    int top=-1;
    int len=strlen(exp);
    for(int i=0;i<len;i++){
        char c=exp[i];
        if(isalnum(c)) printf("%c",c);
        else if(c=='(') stack[++top]=c;
        else if(c==')'){
            while(top!=-1 && stack[top]!='(') printf("%c",stack[top--]);
            if(top!=-1) top--; 
        }
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(c)) printf("%c",stack[top--]);
            stack[++top]=c;
        }
    }
    while(top!=-1) printf("%c",stack[top--]);
    printf("\n");
}
int main(){
    int t;
    scanf("%d",&t);
    char exp[1000];
    getchar();
    for(int i=0;i<t;i++){
        scanf("%s",exp);
        infixToPostfix(exp);
    }
    return 0;
}





