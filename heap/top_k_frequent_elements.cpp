#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map<int,int> freq;

    for(int x:nums)
        freq[x]++;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for(auto it:freq){

        pq.push({it.second,it.first});

        if(pq.size()>k)
            pq.pop();
    }

    vector<int> result;

    while(!pq.empty()){
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;
}

int main(){

    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> ans = topKFrequent(nums,k);

    for(int x:ans)
        cout<<x<<" ";

}
