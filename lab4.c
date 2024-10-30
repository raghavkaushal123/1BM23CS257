#include <stdio.h>
#define N 3
int queue[N];
int front , rear = -1;
void insert(int x){
if(rear == N-1)
printf("Queue overflow\n");

else{
    rear = rear + 1;
    queue[rear] = x;
}
}
void delete(){
    if(front == -1)
        printf("Queue underflow\n");
    else if(front == rear)
        front = rear = -1;
    else{
        front = front + 1;
    }
}
void display(){
    if(front == -1){
        printf("Queue is empty");
    }
    else
        for(int i = front; i<=rear; i++){
            printf("%d",queue[i]);
    }
}
int main(){
    int choice ,x;
    printf("1. insert\n 2. delete\n 3. display\n 4. Exit\n ");
    while(choice != 4){
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value has to be inserted:\n");
                    scanf("%d",&x);
                    insert(x);
                    break;
            case 2:
            delete();
            break;
            case 3:
                display();
                break;
            default: printf("Invalid choice");



        }
    }


}
