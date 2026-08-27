#include <iostream>
#include <vector>
using namespace std;

void cyclicSort(vector<int> &arr)
{
    int i = 0;

    while (i < arr.size())
    {
        int correct = arr[i] - 1;

        if (arr[i] != arr[correct])
        {
            swap(arr[i], arr[correct]);
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements (numbers from 1 to " << n << "): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nArray before sorting: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    cyclicSort(arr);

    cout << "\nArray after sorting: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}