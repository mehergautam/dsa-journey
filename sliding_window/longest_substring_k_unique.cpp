#include <iostream>
#include <unordered_map>
using namespace std;

int longestKUnique(string s, int k){

    unordered_map<char,int> mp;
    int i=0, maxLen=0;

    for(int j=0;j<s.size();j++){

        mp[s[j]]++;

        while(mp.size() > k){
            mp[s[i]]--;
            if(mp[s[i]] == 0)
                mp.erase(s[i]);
            i++;
        }

        if(mp.size() == k)
            maxLen = max(maxLen, j-i+1);
    }

    return maxLen;
}

int main(){

    string s = "aabacbebebe";
    int k = 3;

    cout<<"Length: "<<longestKUnique(s,k);
}
