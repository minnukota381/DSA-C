#include <stdio.h>

// void shellSort(int arr[], int n) {
//     for (int gap = n / 2; gap > 0; gap /= 2) {
//         for (int i = gap; i < n; i++) {
//             int temp = arr[i];
//             int j;
//             for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
//                 arr[j] = arr[j - gap];
//             }
//             arr[j] = temp;
//         }
//     }
// }

void shellSortw(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {45, 23, 53, 12, 64, 77, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    shellSortw(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
