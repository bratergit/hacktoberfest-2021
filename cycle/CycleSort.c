#include <stdio.h>

// Function to implement Cycle Sort
void cycleSort(int arr[], int n) {
    // Traverse array elements and put them to the right place
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        int item = arr[cycle_start];

        // Find the position where we put the element
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }

        // If the element is already in the correct position
        if (pos == cycle_start) {
            continue;
        }

        // Ignore all duplicate elements
        while (item == arr[pos]) {
            pos++;
        }

        // Put the item to its right position
        if (pos != cycle_start) {
            int temp = item;
            item = arr[pos];
            arr[pos] = temp;
        }

        // Rotate the rest of the cycle
        while (pos != cycle_start) {
            pos = cycle_start;

            // Find the position where we put the element
            for (int i = cycle_start + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }

            // Ignore all duplicate elements
            while (item == arr[pos]) {
                pos++;
            }

            // Put the item to its right position
            if (item != arr[pos]) {
                int temp = item;
                item = arr[pos];
                arr[pos] = temp;
            }
        }
    }
}

// Driver program to test above function
int main() {
    int arr[] = {4, 1, 3, 2, 5, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    cycleSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
