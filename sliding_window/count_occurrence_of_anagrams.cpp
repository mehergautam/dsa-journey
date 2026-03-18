#include <iostream>
#include <unordered_map>
using namespace std;

int countAnagrams(string txt, string pat){

    unordered_map<char,int> mp;

    for(char c:pat)
        mp[c]++;

    int count = mp.size();
    int i=0, j=0, ans=0;

    while(j < txt.size()){

        if(mp.find(txt[j]) != mp.end()){
            mp[txt[j]]--;
            if(mp[txt[j]] == 0)
                count--;
        }

        if(j - i + 1 < pat.size())
            j++;

        else if(j - i + 1 == pat.size()){

            if(count == 0)
                ans++;

            if(mp.find(txt[i]) != mp.end()){
                if(mp[txt[i]] == 0)
                    count++;
                mp[txt[i]]++;
            }

            i++;
            j++;
        }
    }

    return ans;
}

int main(){

    string txt = "forxxorfxdofr";
    string pat = "for";

    cout<<"Count: "<<countAnagrams(txt, pat);
}
