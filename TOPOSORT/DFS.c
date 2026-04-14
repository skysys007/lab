#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

void push(int v){
    stack[++top] = v;

}

void DFS(int v){
    visited[v] = 1;
    for (int i = 0; i < n; i++)
    {
        DFS(i);
    }
    push(v);
}

void topoSort(int v){
    visited[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }
    while (top!=-1)
    {
        printf("%d\t", stack[top--]);
    }
    
    
    
}

int main() {
    
    return 0;
}