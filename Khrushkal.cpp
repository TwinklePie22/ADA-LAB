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