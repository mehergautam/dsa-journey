#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int minSubsetSumDiff(vector<int>& arr) {

    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);

    vector<vector<bool>> dp(n+1, vector<bool>(sum+1,false));

    for(int i=0;i<=n;i++)
        dp[i][0] = true;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){

            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    int diff = INT_MAX;

    for(int j=0;j<=sum/2;j++){
        if(dp[n][j])
            diff = min(diff, sum - 2*j);
    }

    return diff;
}

int main(){

    vector<int> arr = {1,6,11,5};

    cout<<"Minimum Difference: "<<minSubsetSumDiff(arr);

    return 0;
}
