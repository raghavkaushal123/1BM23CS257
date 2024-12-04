#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1 ,rear = -1;

void enqueue(int v){
    if(rear == MAX-1){
        printf("Queue overflow\n");
    }
    else{
        if(front == -1)
        front = 0;
        queue[++rear] = v;
    }
}

int dequeue(){
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
        return -1;
    }
    else{
        return queue[front++];
    }
}

int isQueueEmpty(){
    return (front == -1 || front>rear);
}

void bfs(int start , int n){
    printf("BFS traversal starting from vertex %d:",start);
    enqueue(start);
    visited[start] = 1;

    while(!isQueueEmpty()){
        int current = dequeue();
        printf("%d ",current);

        for(int i=0 ; i<n; i++){
            if(adj[current][i] == 1 && !visited[i]){
                enqueue(i);
                visited[i] = 1;
            }
        }

    }
    printf("\n");
}

int main(){
    int n ,start;
    printf("Enter the number of vertices in the graph:");
    scanf("%d",&n);

    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&adj[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        visited[i] = 0;
    }

    printf("Enter the starting vertex for BFS:");
    scanf("%d",&start);
    bfs(start,n);

    return 0;





}
