#include <iostream>
#include <vector>

using namespace std;

void transitiveClosure(vector<vector<int>>& graph) {
    int n = graph.size();

    // Initialize the transitive closure matrix
    vector<vector<int>> closure(n, vector<int>(n, 0));

    // Set initial values based on the input graph
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            closure[i][j] = graph[i][j];

    // Update the closure matrix using Warshall's algorithm
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);

    // Print the transitive closure matrix
    cout << "Transitive Closure Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << closure[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nTime Complexity: O(n^3)" << endl;
    cout << "Space Complexity: O(n^2)" << endl;
}

int main() {
    // Example graph representing directed edges between systems
    vector<vector<int>> graph = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    transitiveClosure(graph);

    return 0;
}
