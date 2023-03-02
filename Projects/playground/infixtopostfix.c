
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char *infixToPostfix(char *infix){
    char buffer[102];
    int tb=-1;
    char postfix[102];
    int tfix=-1;
    int len=strlen(infix);
    for (int i=0;i<len;i++){

        if (isalnum(infix[i])){
            tfix++;
            postfix[tfix]=infix[i];
        }
        else if (infix[i]=='('){
                    tb++;
                    buffer[tb]=infix[i];
                 }
        else if (infix[i]==')'){
            while (buffer[tb]!='('){
                    tfix++;
                    postfix[tfix]=buffer[tb];
                    buffer[tb]='\0';
                    tb--;
                   }
        }
        else if (isOperator(infix[i])){
            if (precedence(buffer[tb])>=precedence(infix[i])){
                while (tb>-1 && (precedence(buffer[tb])>=precedence(infix[i]))){
                       postfix[++tfix]=buffer[tb--];
                       }
                buffer[tb++]=infix[i];
            }
            else{
                buffer[++tb]=infix[i];

            }
        }
    }
    int temp=0;
    while (temp<=tfix){
        printf("%c",postfix[temp]);
        temp++;
    }
    while (tb!=-1){
        printf("%c",buffer[tb--]);
    }
}
void main(){
    char infix[100];
    printf("Enter an infix expression: ");
    gets(infix);
    printf("Postfix expression:");
    infixToPostfix(infix);
    //free(postfix);
}
