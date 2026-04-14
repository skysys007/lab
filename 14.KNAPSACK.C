#include <stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int main() {
    int n, m;
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity of Knapsack: ");
    scanf("%d", &m);

    int p[n+1], wt[n+1];

    printf("Enter profits:\n");
    for (int i = 1; i <= n; i++){
        printf("Enter profit %d: ", i);
        scanf("%d", &p[i]);
    }

    printf("Enter weights:\n");
    for (int i = 1; i <= n; i++){
        printf("Enter weight %d: ", i);
        scanf("%d", &wt[i]);
    }

    int V[n+1][m+1];

    for (int w = 0; w <= m; w++){
        V[0][w] = 0;
    }

    for (int i = 1; i <= n; i++){
        for (int w = 0; w <= m; w++){
            if (wt[i] <= w){
                V[i][w] = max(V[i-1][w], p[i] + V[i-1][w - wt[i]]);
            } else {
                V[i][w] = V[i-1][w];
            }
        }
    }

    printf("Maximum Profit: %d\n", V[n][m]);

    int w = m;
    printf("Selected Items:\n");
    for (int i = n; i > 0; i--){
        if (V[i][w] != V[i-1][w]){
            printf("Item %d (Profit=%d, Weight=%d)\n", i, p[i], wt[i]);
            w = w - wt[i];
        }
    }

    return 0;
}