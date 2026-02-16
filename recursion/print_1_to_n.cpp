// Problem: Print 1 to N using Recursion
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
using namespace std;

void printNumbers(int n) {
    if(n == 0)
        return;
    printNumbers(n - 1);
    cout << n << " ";
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    printNumbers(n);
    return 0;
}
