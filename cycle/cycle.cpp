#include <iostream>
#include <vector>
#include <algorithm>

// Function to sort the array using Cycle Sort and return the write count
int cycleSort(std::vector<int>& arr) {
    int writes = 0;
    int n = arr.size();

    // Loop through the array to find cycles
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        int item = arr[cycle_start];
        int pos = cycle_start;

        // Count how many elements are smaller than the item
        for (int i = cycle_start + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }

        // If the item is already in the correct position, skip it
        if (pos == cycle_start) {
            continue;
        }

        // Ignore duplicate elements by moving to the next position
        while (item == arr[pos]) {
            pos++;
        }

        // Put the item into its correct position
        if (pos != cycle_start) {
            std::swap(item, arr[pos]);
            writes++;
        }

        // Rotate the rest of the cycle
        while (pos != cycle_start) {
            pos = cycle_start;

            // Find where to put the element
            for (int i = cycle_start + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }

            // Skip duplicate elements
            while (item == arr[pos]) {
                pos++;
            }

            // Put the item in its correct position
            if (item != arr[pos]) {
                std::swap(item, arr[pos]);
                writes++;
            }
        }
    }
    return writes;
}

int main() {
    std::vector<int> arr = {4, 3, 2, 5, 1, 4, 2};
    
    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n";

    int total_writes = cycleSort(arr);

    std::cout << "Sorted array:   ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n";
    
    std::cout << "Total memory writes: " << total_writes << "\n";

    return 0;
}
