#include <bits/stdc++.h> 
using namespace std; 

class DSU { 
	int* parent; 
	int* rank; 
public: 
	DSU(int n) 
	{ 
		parent = new int[n]; 
		rank = new int[n]; 
		for (int i = 0; i < n; i++) { 
			parent[i] = -1; 
			rank[i] = 1; 
		} 
	} 
	int find(int i) 
	{ 
		if (parent[i] == -1) 
			return i; 
		return parent[i] = find(parent[i]); 
	} 
	void unite(int x, int y) 
	{ 
		int s1 = find(x); 
		int s2 = find(y); 
		if (s1 != s2) { 
			if (rank[s1] < rank[s2])  
				parent[s1] = s2; 
			else if (rank[s1] > rank[s2]) 
				parent[s2] = s1;  
			else { 
				parent[s2] = s1; 
				rank[s1] += 1; 
			} 
		} 
	} 
}; 
class Graph { 
	vector<vector<int> > edgelist; 
	int V; 
public: 
	Graph(int V) { this->V = V; } 
	void addEdge(int x, int y, int w) 
	{ 
		edgelist.push_back({ w, x, y }); 
	} 
	void kruskals_mst() 
	{ 
		sort(edgelist.begin(), edgelist.end()); 
		DSU s(V); 
		int ans = 0; 
		cout << "Following are the edges in the constructed MST" << endl; 
		for (auto edge : edgelist) { 
			int w = edge[0]; 
			int x = edge[1]; 
	  		int y = edge[2]; 
			if (s.find(x) != s.find(y)) { 
				s.unite(x, y); 
				ans += w; 
				cout << x << " - " << y << " == " << w << endl; 
			} 
		} 
		cout << "Minimum Cost Spanning Tree: " << ans << endl; 
	} 
}; 
int main() 
{ 
	Graph g(4); 
	g.addEdge(0, 1, 10); 
	g.addEdge(1, 3, 15); 
	g.addEdge(2, 3, 4); 
	g.addEdge(2, 0, 6); 
	g.addEdge(0, 3, 5); 

	g.kruskals_mst(); 
	return 0; 
}
/* 
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(connections.begin(), connections.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        int ans = 0;
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (auto& e : connections) {
            int x = e[0] - 1, y = e[1] - 1, cost = e[2];
            if (find(x) == find(y)) {
                continue;
            }
            p[find(x)] = find(y);
            ans += cost;
            if (--n == 1) {
                return ans;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> connections = {{1, 2, 5}, {1, 3, 6}, {2, 3, 1}};
    int n = 3;
    int result = solution.minimumCost(n, connections);
    cout << "The minimum cost is: " << result << endl;
    return 0;
}  
*/
