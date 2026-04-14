#include <stdio.h>

int comps = 0;

int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    while (i <= j){
        while (i <= high && (++comps && A[i] <= pivot)){
            i++;
        }
        while (j >= low && (++comps && A[j] > pivot)){
            j--;
        }
        if (i < j){
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void quickSort(int A[], int low, int high){
    if (low < high){
        int p = partition(A, low, high);
        quickSort(A, low, p - 1);
        quickSort(A, p + 1, high);
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    printf("Total comparisons: %d\n", comps);

    return 0;
}