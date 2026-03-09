#include <iostream>
#include <vector>
using namespace std;

int rodCutting(vector<int>& price, int n){

    vector<int> dp(n+1,0);

    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i] = max(dp[i], price[j] + dp[i-j-1]);
        }
    }

    return dp[n];
}

int main(){

    vector<int> price = {1,5,8,9,10,17,17,20};
    int n = price.size();

    cout<<"Maximum Profit: "<<rodCutting(price,n);

    return 0;
}
