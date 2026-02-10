// Problem: Find sum of all elements in an array
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    int sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << sum;
    return 0;
}
