// Problem: Factorial using Recursion
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
using namespace std;

int factorial(int n) {
    if(n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial: " << factorial(n);
    return 0;
}
