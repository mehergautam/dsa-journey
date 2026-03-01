#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii; // {distance, node}

void dijkstra(int n, vector<vector<pii>> &adj, int src) {
    vector<int> dist(n, 1e9);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(d > dist[node]) continue;

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;

            if(dist[node] + weight < dist[adjNode]) {
                dist[adjNode] = dist[node] + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    cout << "Shortest distances from source:\n";
    for(int i = 0; i < n; i++)
        cout << "Node " << i << " -> " << dist[i] << endl;
}

int main() {
    int n = 5;
    vector<vector<pii>> adj(n);

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    dijkstra(n, adj, 0);

    return 0;
}
