// Problem: Count even and odd numbers in an array
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    int even = 0, odd = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];

        if(arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    cout << "Even: " << even << endl;
    cout << "Odd: " << odd << endl;

    return 0;
}
