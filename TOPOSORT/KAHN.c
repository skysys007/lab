#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int front = -1, rear = -1;
int queue[MAX];

void enqueue(int s){
    if (rear == MAX -1)
    {
        printf("Q O");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    queue[++rear] = s;
} 

int dequeue(){
    if (front == -1)
    {
        printf("Q U");
        return -1;
    }
    int x = queue[front] ;
    if (front == rear)
    {
        front = -1;
        rear = -1;    
    }else
    {
        front++;

    }
    return x;   
}

int isEmpty(){
    return front == -1;
}

void topoSort(int graph[MAX][MAX], int n){
    int indegree[MAX] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                indegree[j]++;
            }
        }   
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            enqueue(i);
        }
    }

    int count = 0;
    while (!isEmpty())
    {
        int node = dequeue();
        printf("%d ", node);
        count++;
        for (int j = 0; j < n; j++)
        {
            if (graph[node][j] == 1)
            {
                indegree[j]--;
                if (indegree[j] == 0)
                {
                    enqueue(j);
                }
                
            }
            
        }
        
    }
    
    if (count != n)
    {
        printf("Cycle Deetcted");
    }
    
    
}


int main() {
    
    return 0;
}