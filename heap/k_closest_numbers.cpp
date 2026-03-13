#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kClosest(vector<int>& arr, int k, int x){

    priority_queue<pair<int,int>> pq;

    for(int num:arr){

        pq.push({abs(num-x),num});

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

    vector<int> arr = {5,6,7,8,9};
    int k = 3;
    int x = 7;

    vector<int> res = kClosest(arr,k,x);

    for(int x:res)
        cout<<x<<" ";
}
