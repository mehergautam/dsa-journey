#include <iostream>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); // Path Compression
        return parent[x];
    }

    void unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] < rank[py])
            parent[px] = py;
        else if(rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

int main() {
    DSU dsu(5);

    dsu.unionSet(0, 1);
    dsu.unionSet(1, 2);

    if(dsu.find(0) == dsu.find(2))
        cout << "Connected\n";
    else
        cout << "Not Connected\n";

    return 0;
}
