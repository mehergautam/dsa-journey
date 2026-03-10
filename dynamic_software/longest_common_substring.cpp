#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubstring(string a, string b){

    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    int ans = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
        }
    }

    return ans;
}

int main(){

    string a = "abcde";
    string b = "abfce";

    cout<<"Longest Common Substring Length: "<<longestCommonSubstring(a,b);

    return 0;
}
