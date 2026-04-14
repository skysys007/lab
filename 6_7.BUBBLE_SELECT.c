#include <stdio.h>
#include <stdlib.h>

int b_comps = 0;
int b_swaps = 0;

void bubbleSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            b_comps++;
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                b_swaps++;
            }
        }
    }
}

int s_comps = 0;
int s_swaps = 0;

void selectionSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++){
        int min = i;
        for (int j = i + 1; j < size; j++){
            s_comps++;
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if (min != i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
            s_swaps++;
        }
    }
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    int arr[size], arr1[size];

    printf("Enter elements:\n");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
        arr1[i] = arr[i];
    }

    bubbleSort(arr, size);
    selectionSort(arr1, size);

    printf("\nBubble Sorted Array: ");
    printArray(arr, size);
    printf("Bubble Comparisons: %d\n", b_comps);
    printf("Bubble Swaps: %d\n", b_swaps);

    printf("\nSelection Sorted Array: ");
    printArray(arr1, size);
    printf("Selection Comparisons: %d\n", s_comps);
    printf("Selection Swaps: %d\n", s_swaps);

    return 0;
}