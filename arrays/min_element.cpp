// Problem: Find minimum element in an array
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minElement = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    cout << minElement;

    return 0;
}
