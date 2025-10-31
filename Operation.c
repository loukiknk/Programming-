#include<stdio.h>
#include<math.h>
#include<ctype.h>
float stack[50];
int top=-1;
void push(float x);
float pop();
float eval(char postfix[]);
float oper(char symb,float op1,float op2);
void push(float x){
    stack[++top]=x;
}
float pop(){
    return stack[top--];
}
float eval(char postfix[]){
    float res,op1,op2;
    char ch;
    int i=0;
    while((ch=postfix[i])!='\0'){
        if(isdigit(ch)){
            push(ch-'0');
        }else{
            op2=pop();
            op1=pop();
            res=oper(ch,op1,op2);
            push(res);
        }
        i++;
    }    
    return pop();
}
float oper(char symb ,float op1,float op2){
    switch(symb){
        case '^':
            return pow(op1,op2);
            break;
            case '*':
            return op1*op2;
            break;
            case '/':
            return op1/op2;
            break;
            case '+':
            return op1+op2;
            break;
            case '-':
            return op1-op2;
            break;
            default:
            return 0;
    }
}
int main(){
    char postfix [50];
    float res;
    printf("enter the postfix expression");
    scanf(" %s",&postfix);
    res=eval(postfix);
    printf(" %f",res);
    return 0;
}
