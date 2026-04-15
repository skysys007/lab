#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int front = -1, rear = -1;
int queue[MAX];
int comparisons = 0; // count comparisons

void enqueue(int s){
    if (rear == MAX - 1){
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1){
        front = 0;
    }
    queue[++rear] = s;
}

int dequeue(){
    if (front == -1){
        printf("Queue Underflow\n");
        return -1;
    }
    int x = queue[front];
    if (front == rear){
        front = rear = -1;
    } else {
        front++;
    }
    return x;
}

int isEmpty(){
    comparisons++;
    return front == -1;
}

void topoSort(int graph[MAX][MAX], int n){
    int indegree[MAX] = {0};

    // calculate indegree
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            comparisons++;
            if (graph[i][j] == 1){
                indegree[j]++;
            }
        }
    }

    // enqueue nodes with indegree 0
    for (int i = 0; i < n; i++){
        comparisons++;
        if (indegree[i] == 0){
            enqueue(i);
        }
    }

    int count = 0;

    printf("Topological Order:\n");

    while (!isEmpty()){
        int node = dequeue();
        printf("%d ", node);
        count++;

        for (int j = 0; j < n; j++){
            comparisons++;
            if (graph[node][j] == 1){
                indegree[j]--;

                comparisons++;
                if (indegree[j] == 0){
                    enqueue(j);
                }
            }
        }
    }

    if (count != n){
        printf("\nCycle Detected\n");
    }

    printf("\nComparisons: %d\n", comparisons);
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    topoSort(graph, n);

    return 0;
}
