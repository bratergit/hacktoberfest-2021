#include<iostream>
#include<vector>
using namespace std;

void binary_search(vector<int> &arr, int key)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == key)
        {
            cout << "Element found at index " << mid << endl;
            return;
        }
        else if(arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << "Element not found";
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted array elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter key: ";
    cin >> key;

    binary_search(arr, key);

    return 0;
}