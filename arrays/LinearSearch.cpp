// Problem: Linear Search in an array
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
    int key;
    cin >> key;
    int index = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            index = i;
            break;
        }
    }
    cout << index;
    return 0;
}
