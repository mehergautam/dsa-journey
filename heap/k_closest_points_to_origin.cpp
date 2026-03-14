#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

    priority_queue<pair<int, vector<int>>> pq;

    for(auto &p : points){

        int dist = p[0]*p[0] + p[1]*p[1];

        pq.push({dist, p});

        if(pq.size() > k)
            pq.pop();
    }

    vector<vector<int>> result;

    while(!pq.empty()){
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;
}

int main(){

    vector<vector<int>> points = {{1,3},{-2,2},{5,8}};
    int k = 2;

    vector<vector<int>> ans = kClosest(points,k);

    for(auto p:ans)
        cout<<p[0]<<" "<<p[1]<<endl;
}
