#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4;

    // Adjacency Matrix
    int matrix[4][4] = {0};

    matrix[0][1] = matrix[1][0] = 1;
    matrix[1][2] = matrix[2][1] = 1;
    matrix[2][3] = matrix[3][2] = 1;

    cout << "Adjacency Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    // Adjacency List
    vector<int> adj[4];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    cout << "\nAdjacency List:\n";
    for(int i=0;i<n;i++){
        cout << i << " -> ";
        for(int v: adj[i])
            cout << v << " ";
        cout << endl;
    }

    return 0;
}
