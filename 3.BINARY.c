#include <stdio.h>
#include <time.h>

int l_comps = 0, b_comps = 0;

int linearSearch(int arr[], int size, int key){
    for (int i = 0; i < size; i++)
    {
        l_comps++;
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int key){
    int low = 0;
    int high = size-1;

    while (low<=high)
    {
        b_comps++;
        int mid = (low+high)/2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid]<key)
        {
            low = mid + 1;
        }else
        {
            high = mid -1;
        }
    }
    return -1;
}

int main() {
    int size, key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements in the sorted array:\n");
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

    if (found>=0)
    {
        printf("Element found at position: %d\n", (found+1));
        time = ((double)(end-start))/CLOCKS_PER_SEC;
        printf("Time taken for linear Search: %f\n", time);
    }else
    {
        printf("Element not found\n");
    }

    printf("Linear Comparisons: %d\n", l_comps);

    start = clock();
    found = binarySearch(arr, size, key);
    end =clock();

    if (found>=0)
    {
        printf("Element found at position: %d\n", (found+1));
        time = ((double)(end-start))/CLOCKS_PER_SEC;
        printf("Time taken for Binary Search: %f\n", time);
    }else
    {
        printf("Element not found\n");
    }

    printf("binary Search Comparisons: %d\n", b_comps);

    return 0;
}