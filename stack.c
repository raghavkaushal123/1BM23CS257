#include <stdio.h>
#define N 5
int stack[N] , top = -1;
void push(int);
void pop();
void display();
void push(int x){
    if(top == N-1){
        printf("Stack overflow");
    }
    else{
        top++;
        stack[top] = x;
        printf("Inserted value is:%d\n",stack[top]);
    }
}
void pop(){
    if(top == -1){
        printf("Stack underflow");
    }
    else{
        top--;
        printf("Deletion successful");
        int element = stack[top];
        printf("Deleted element is:%d",element);
    }
}
void display(){
    for(int i = top; i>=0 ; i--){
        printf("%d",stack[i]);
    }
}
void main(){
    int choice , x;
    printf("1.push\n2.pop\n3.display\n4.exit\n");
    while(choice != 4){
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("Enter the value has to be inserted:\n");
        scanf("%d",&x);
        push(x);
        break;
        case 2: pop();
        break;
        case 3: display();
        break;
        default: printf("Invalid choice");

    }
    
}



}
