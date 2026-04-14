#include <stdio.h>
#include <time.h>

int linearSearch(int arr[], int size, int key){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main() {
    int size, key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements in the array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    clock_t start, end;
    double time;

    start = clock();
    int found = linearSearch(arr, size, key);
    end = clock();

    if (found >= 0)
    {
        printf("Element found at position: %d\n", (found + 1));
        time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for Linear Search: %f seconds\n", time);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}