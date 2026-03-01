#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &pathVis) {
    visited[node] = 1;
    pathVis[node] = 1;

    for(int v : adj[node]) {
        if(!visited[v]) {
            if(dfs(v, adj, visited, pathVis))
                return true;
        }
        else if(pathVis[v]) {
            return true; // cycle found
        }
    }

    pathVis[node] = 0;
    return false;
}

int main() {
    int n = 4;
    vector<int> adj[4];

    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {1}; // cycle

    vector<int> visited(n, 0), pathVis(n, 0);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, adj, visited, pathVis)) {
                cout << "Cycle Detected";
                return 0;
            }
        }
    }

    cout << "No Cycle";
    return 0;
}
