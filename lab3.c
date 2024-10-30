
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define N 100

char stack[N];
int top = -1;

void push(char c) {
    if (top == N - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = c;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0'; 
    } else {
        return stack[top--];
    }
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    char c;
    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        } else if (isOperator(c)) {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    
    
    while (top != -1) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';
}

int main() {
    char infix[N], postfix[N];
    printf("Enter infix expression:\n");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression is: %s\n", postfix);
    return 0;
}
