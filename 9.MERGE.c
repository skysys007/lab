#include <stdio.h>

int comps = 0;

void merge(int A[], int low, int mid, int high){
    int i = low, j = mid + 1, k = low;
    int B[high + 1];

    while (i <= mid && j <= high){
        comps++;
        if (A[i] <= A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }

    while (i <= mid){
        B[k++] = A[i++];
    }

    while (j <= high){
        B[k++] = A[j++];
    }

    for (int i = low; i <= high; i++){
        A[i] = B[i];
    }
}

void mergeSort(int arr[], int low, int high){
    if (low < high){
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    printf("Total comparisons: %d\n", comps);

    return 0;
}