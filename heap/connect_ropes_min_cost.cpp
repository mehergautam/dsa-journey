#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minCost(vector<int>& ropes){

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int r:ropes)
        pq.push(r);

    int cost = 0;

    while(pq.size() > 1){

        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        int sum = first + second;

        cost += sum;

        pq.push(sum);
    }

    return cost;
}

int main(){

    vector<int> ropes = {4,3,2,6};

    cout<<"Minimum Cost: "<<minCost(ropes);
}
