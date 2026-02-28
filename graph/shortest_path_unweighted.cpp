#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void shortestPath(int src, int n, vector<int> adj[]) {
    vector<int> dist(n, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int v : adj[node]) {
            if(dist[v] == -1) {
                dist[v] = dist[node] + 1;
                q.push(v);
            }
        }
    }

    cout << "Shortest distances from source:\n";
    for(int i = 0; i < n; i++)
        cout << "Node " << i << " -> " << dist[i] << endl;
}

int main() {
    int n = 6;
    vector<int> adj[6];

    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,4};
    adj[3] = {1,5};
    adj[4] = {2};
    adj[5] = {3};

    shortestPath(0, n, adj);

    return 0;
}
