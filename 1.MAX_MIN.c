#include <stdio.h>

int main() {
    int arr[] = {4567, 73, 7, 13, 5, 135, 3, 513513};
    int size = 8;

    int max = arr[0], min = arr[0];
    int minComp = 0, maxComp = 0;

    for (int i = 1; i < size; i++) {
        minComp++;
        if (arr[i] < min) {
            min = arr[i];
        }

        maxComp++;
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("MAX: %d\n", max);
    printf("MIN: %d\n", min);
    printf("Min Comparisons: %d\n", minComp);
    printf("Max Comparisons: %d\n", maxComp);

    return 0;
}