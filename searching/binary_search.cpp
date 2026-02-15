// Problem: Binary Search (Iterative)
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int left = 0, right = n - 1;
    int found = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == key) {
            found = mid;
            break;
        }
        else if(arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if(found != -1)
        cout << "Element found at index " << found;
    else
        cout << "Element not found";

    return 0;
}
