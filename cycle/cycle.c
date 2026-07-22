#include <stdio.h>

// Function to perform Cycle Sort and return total memory writes
int cycleSort(int arr[], int n) {
    int writes = 0;

    // Loop through the array to find distinct cycles
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        int item = arr[cycle_start];
        int pos = cycle_start;

        // Count how many elements are smaller than the current item
        for (int i = cycle_start + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }

        // If the item is already in the correct position, skip it
        if (pos == cycle_start) {
            continue;
        }

        // Handle duplicate elements by moving past them
        while (item == arr[pos]) {
            pos++;
        }

        // Put the item into its correct position
        if (pos != cycle_start) {
            int temp = arr[pos];
            arr[pos] = item;
            item = temp;
            writes++;
        }

        // Rotate the remaining elements in the current cycle
        while (pos != cycle_start) {
            pos = cycle_start;

            // Find the correct position for the new displaced item
            for (int i = cycle_start + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }

            // Move past duplicate elements
            while (item == arr[pos]) {
                pos++;
            }

            // Swap the item into its correct position
            if (item != arr[pos]) {
                int temp = arr[pos];
                arr[pos] = item;
                item = temp;
                writes++;
            }
        }
    }
    return writes;
}

// Driver code to test the algorithm
int main() {
    int arr[] = {4, 3, 2, 1, 4, 2, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int total_writes = cycleSort(arr, n);

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Total memory writes: %d\n", total_writes);

    return 0;
}
