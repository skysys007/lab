#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n, e;

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void resetVisited() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

void resetQueue() {
    front = rear = -1;
}

void DFS(int v){
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++){
        if (!visited[i] && adj[v][i] == 1){
            DFS(i);
        }
    }
}

void BFS(int start){
    enqueue(start);
    visited[start] = 1;
  
    while(front <= rear){
        int current = dequeue();
        printf("%d ", current);

        for(int i = 0; i < n; i++){
            if(adj[current][i] == 1 && !visited[i]){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    int start;
    printf("Enter starting node: ");
    scanf("%d", &start);

    resetVisited();
    printf("DFS Traversal: ");
    DFS(start);

    resetVisited();
    resetQueue();
    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}