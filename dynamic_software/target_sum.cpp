#include <iostream>
#include <vector>
using namespace std;

int countSubsets(vector<int>& nums, int sum){

    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(sum+1,0));

    for(int i=0;i<=n;i++)
        dp[i][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){

            if(nums[i-1] <= j)
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];
}

int findTargetSumWays(vector<int>& nums, int target){

    int sum = 0;
    for(int x:nums)
        sum += x;

    int s1 = (sum + target) / 2;

    return countSubsets(nums, s1);
}

int main(){

    vector<int> nums = {1,1,1,1,1};
    int target = 3;

    cout<<"Ways: "<<findTargetSumWays(nums,target);

    return 0;
}
