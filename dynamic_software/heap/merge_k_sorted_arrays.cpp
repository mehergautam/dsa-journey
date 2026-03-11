#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>>& arr){

    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto &v : arr){
        for(int x : v)
            pq.push(x);
    }

    vector<int> result;

    while(!pq.empty()){
        result.push_back(pq.top());
        pq.pop();
    }

    return result;
}

int main(){

    vector<vector<int>> arr = {{1,4,7},{2,5,8},{3,6,9}};

    vector<int> res = mergeKArrays(arr);

    for(int x:res)
        cout<<x<<" ";

    return 0;
}
