#include <iostream>
#include <vector>
using namespace std;

// Memoization
int fibMemo(int n, vector<int> &dp) {
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];

    return dp[n] = fibMemo(n-1, dp) + fibMemo(n-2, dp);
}

// Tabulation
int fibTab(int n) {
    if(n <= 1) return n;

    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

int main() {
    int n = 10;

    vector<int> dp(n+1, -1);

    cout << "Memoization: " << fibMemo(n, dp) << endl;
    cout << "Tabulation: " << fibTab(n) << endl;

    return 0;
}
