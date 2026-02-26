#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for(int v : adj[node]) {
        if(!visited[v])
            dfs(v, adj, visited);
    }
}

int main() {
    int n = 5;
    vector<int> adj[5];

    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,4};
    adj[3] = {1};
    adj[4] = {2};

    vector<bool> visited(n, false);

    cout << "DFS Traversal: ";
    dfs(0, adj, visited);

    return 0;
}
