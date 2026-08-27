#include <stdio.h>

// Function to find the maximum element using Binary Search
int findMaximum(int arr[], int low, int high) {
    // Base case: Only one element left
    if (low == high) {
        return arr[low];
    }

    // Base case: Only two elements left
    if (high == low + 1) {
        return (arr[low] > arr[high]) ? arr[low] : arr[high];
    }

    int mid = low + (high - low) / 2;

    // Check if mid element is the maximum
    if (mid < high && arr[mid] > arr[mid + 1]) {
        return arr[mid];
    }

    // Check if element before mid is the maximum
    if (mid > low && arr[mid] < arr[mid - 1]) {
        return arr[mid - 1];
    }

    // Decide whether to search in the left half or right half
    if (arr[low] > arr[mid]) {
        return findMaximum(arr, low, mid - 1); // Search left half
    } else {
        return findMaximum(arr, mid + 1, high); // Search right half
    }
}

int main() {
    int arr[] = {4, 5, 6, 7, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_val = findMaximum(arr, 0, n - 1);
    printf("The maximum element in the array is: %d\n", max_val);

    return 0;
}
