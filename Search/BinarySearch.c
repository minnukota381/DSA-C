#include <stdio.h>

void binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    
    while (low <= high) {
        mid = low + (high - low) / 2;
        
        if (arr[mid] == key) {
            printf("Element %d found at position %d\n", key, mid + 1);
            return;
        } else if (arr[mid] < key) {
            low = mid + 1; 
        } else {
            high = mid - 1;
        }
    }

    printf("Element %d not found in the array\n", key);
}

int main() {
    int n, key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    binarySearch(arr, n, key);

    return 0;
}
