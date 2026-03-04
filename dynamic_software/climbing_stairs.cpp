#include <iostream>
#include <vector>
using namespace std;

// Memoization
int climbMemo(int n, vector<int> &dp) {
    if(n <= 2) return n;
    if(dp[n] != -1) return dp[n];

    return dp[n] = climbMemo(n-1, dp) + climbMemo(n-2, dp);
}

// Tabulation
int climbTab(int n) {
    if(n <= 2) return n;

    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

int main() {
    int n = 5;
    vector<int> dp(n+1, -1);

    cout << "Memoization: " << climbMemo(n, dp) << endl;
    cout << "Tabulation: " << climbTab(n) << endl;

    return 0;
}
