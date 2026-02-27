#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topoSort(int n, vector<int> adj[]) {
    vector<int> indegree(n, 0);

    for(int i = 0; i < n; i++)
        for(int v : adj[i])
            indegree[v]++;

    queue<int> q;
    for(int i = 0; i < n; i++)
        if(indegree[i] == 0)
            q.push(i);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int v : adj[node]) {
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }
}

int main() {
    int n = 6;
    vector<int> adj[6];

    adj[5] = {2,0};
    adj[4] = {0,1};
    adj[2] = {3};
    adj[3] = {1};

    cout << "Topological Sort: ";
    topoSort(n, adj);

    return 0;
}
