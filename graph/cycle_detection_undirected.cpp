#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;

    for(int v : adj[node]) {
        if(!visited[v]) {
            if(dfs(v, node, adj, visited))
                return true;
        }
        else if(v != parent) {
            return true; // cycle found
        }
    }
    return false;
}

int main() {
    int n = 5;
    vector<int> adj[5];

    adj[0] = {1};
    adj[1] = {0,2};
    adj[2] = {1,3};
    adj[3] = {2,4};
    adj[4] = {3}; // no cycle

    vector<bool> visited(n, false);

    bool hasCycle = false;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1, adj, visited)) {
                hasCycle = true;
                break;
            }
        }
    }

    if(hasCycle)
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}
