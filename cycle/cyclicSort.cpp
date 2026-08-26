#include <iostream>
using namespace std;

void cyclicSort(int arr[], int n) {
    int i = 0;

    while (i < n) {
        int correctIndex = arr[i] - 1;

        if (arr[i] != arr[correctIndex]) {
            swap(arr[i], arr[correctIndex]);
        } else {
            i++;
        }
    }
}

int main() {
    int arr[] = {3, 5, 2, 1, 4};
    int n = 5;

    cyclicSort(arr, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}