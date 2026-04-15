#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

int comparisons = 0; // count comparisons

void push(int v){
    stack[++top] = v;
}

void DFS(int v){
    visited[v] = 1;

    for (int i = 0; i < n; i++){
        comparisons++; // for checking condition
        if (adj[v][i] == 1 && !visited[i]){
            DFS(i);
        }
    }

    push(v);
}

void topoSort(){
    for (int i = 0; i < n; i++){
        comparisons++;
        if (!visited[i]){
            DFS(i);
        }
    }

    printf("Topological Order:\n");
    while (top != -1){
        printf("%d\t", stack[top--]);
    }

    printf("\nComparisons: %d\n", comparisons);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    // initialize visited
    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }

    topoSort();

    return 0;
}
