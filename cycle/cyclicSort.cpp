#include <iostream>
#include <vector>
using namespace std;

void cyclicSort(vector<int>& arr) {
    int i = 0;

    while (i < arr.size()) {
        int correct = arr[i] - 1;  // Correct index of current element

        if (arr[i] != arr[correct]) {
            swap(arr[i], arr[correct]);
        } else {
            i++;
        }
    }
}

int main() {
    vector<int> arr = {3, 1, 5, 4, 2};

    cyclicSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}