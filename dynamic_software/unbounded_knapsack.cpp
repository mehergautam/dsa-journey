#include <iostream>
#include <vector>
using namespace std;

int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val) {

    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){

            if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W];
}

int main(){

    vector<int> wt = {1,3,4,5};
    vector<int> val = {1,4,5,7};
    int W = 8;

    cout<<"Maximum Value: "<<unboundedKnapsack(W, wt, val);

    return 0;
}
