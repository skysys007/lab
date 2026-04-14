#include <stdio.h>
int comparisons = 0;
int swaps = 0;
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < n){
        comparisons++;
        if (arr[left] > arr[largest])
            largest = left;
    }
    if (right < n){
        comparisons++;
        if (arr[right] > arr[largest])
            largest = right;
    }
    if (largest != i)
    {
        swaps++;
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for (int i = n/2-1; i>=0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n-1; i > 0; i--)
    {
        swaps++;
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        heapify(arr, i, 0);
    } 
    
}

void traverse(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}


int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = 5;

    printf("Original array:\n");
    traverse(arr, n);

    heapSort(arr, n);

    printf("\nSorted array:\n");
    traverse(arr, n);

    printf("\nComparisons: %d\n", comparisons);
    printf("Swaps: %d\n", swaps);

    return 0;
}