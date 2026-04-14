#include <stdio.h>

int comps = 0;

int binarySearch(int arr[], int low, int high, int key) {
    comps++;
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    comps++;
    if (arr[mid] == key)
        return mid;

    comps++;
    if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);

    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", result);

    printf("Total comparisons: %d\n", comps);

    return 0;
}