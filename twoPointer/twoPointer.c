#include <stdio.h>

int main() {
    int arr[] = {2, 3, 5, 8, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 13;

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            printf("Pair found: %d and %d\n", arr[left], arr[right]);
            return 0;
        }
        else if (sum < target) {
            left++;      // Move left pointer to increase the sum
        }
        else {
            right--;     // Move right pointer to decrease the sum
        }
    }

    printf("No pair found.\n");

    return 0;
}
