/*
A DFS based program in which outputs all systems reachable from a given system and also its time and space complexity for a network having ‘n’ systems.
*/


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Network
{
    int n;                   // Number of systems
    vector<vector<int>> adj; // Adjacency list

public:
    Network(int numSystems) : n(numSystems)
    {
        adj.resize(n); // Initialize adjacency list for n systems
    }

    // Function to add an edge between systems
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        // For undirected graph, add the line below to make it bidirectional
        // adj[v].push_back(u);
    }

    // Depth-First Search traversal to find reachable systems
    void DFS(int start, vector<bool> &visited)
    {
        visited[start] = true; // Mark the current system as visited
        cout << start << " ";  // Output the current system (reachable)

        // Traverse all systems adjacent to the current system
        for (int u : adj[start])
        {
            if (!visited[u])
            {
                DFS(u, visited); // Recursive DFS call for unvisited systems
            }
        }
    }

    // Function to find reachable systems from a given system
    void findReachableSystems(int start)
    {
        vector<bool> visited(n, false); // Array to mark visited systems

        cout << "Systems reachable from system " << start << ": ";
        DFS(start, visited);
        cout << endl;
    }
};

int main()
{
    int numSystems = 6; // Number of systems in the network
    Network network(numSystems);

    // Adding edges between systems
    network.addEdge(0, 1);
    network.addEdge(0, 2);
    network.addEdge(1, 3);
    network.addEdge(1, 4);
    network.addEdge(2, 4);
    network.addEdge(3, 5);
    network.addEdge(4, 5);

    int startSystem = 0; // Choose the starting system for DFS traversal
    clock_t start,end;
    start=clock();
    network.findReachableSystems(startSystem);
    end=clock();
    double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
    cout<<"\ntime spent: "<<time_spent;

    return 0;
}
