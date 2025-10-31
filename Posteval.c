#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

int prcd(char ch) {
    switch (ch) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case '(': return -1;
        default: return 0;
    }
}

void conversion(char infix[], char postfix[]) {
    int i = 0, p = 0;
    char ch;
    while ((ch = infix[i]) != '\0') {
        switch (ch) {
            default:
                postfix[p++] = ch;
                break;
            case '(':
                push(ch);
                break;
            case ')':
                while (top != -1 && stack[top] != '(') {
                    postfix[p++] = pop();
                }
                pop();
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while (top != -1 && prcd(stack[top]) >= prcd(ch)) {
                    postfix[p++] = pop();
                }
                push(ch);
                break;
            case '^':
                while (top != -1 && prcd(stack[top]) > prcd(ch)) {
                    postfix[p++] = pop();
                }
                push(ch);
                break;
        }
        i++;
    }
    while (top != -1) {
        postfix[p++] = pop();
    }
    postfix[p] = '\0';
}

int main() {
    char infix[50], postfix[50];
    printf("Enter a valid infix expression: ");
    scanf("%s", infix);
    conversion(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
