#include <iostream>
#include <vector>
#include<ctime>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
      vector<bool> cols(n);
      vector<bool> diag1(2 * n - 1);
      vector<bool> diag2(2 * n - 1);
      vector<string> board(n, string(n, '*'));
      vector<vector<string>> ans;
      dfs(n, 0, cols, diag1, diag2, board, ans);
      return ans;
    }
private:
    void dfs(int n, int i, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, vector<string>& board, vector<vector<string>>& ans) {
        if (i == n) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (cols[j] || diag1[i + j] || diag2[j - i + n - 1])
                continue;
            board[i][j] = 'Q';
            cols[j] = diag1[i + j] = diag2[j - i + n - 1] = true;
            dfs(n, i + 1, cols, diag1, diag2, board, ans);
            cols[j] = diag1[i + j] = diag2[j - i + n - 1] = false;
            board[i][j] = '*';
        }
    }
};
int main() {
    Solution solution;
    int n;
    cout << "Enter the number of queens: ";
    cin>> n;
    clock_t start = clock();
    vector<vector<string>> result = solution.solveNQueens(n);

    cout<<"Number of solutions: \n";
    for (const auto& solution : result) {
        for (const auto& row : solution) {
            cout << row <<" " << endl;
        }
        cout<<"\n";
    }
    clock_t end = clock();
    double time_spent = double(end - start) / CLOCKS_PER_SEC * 1000.0; // Convert to milliseconds
    cout << "Time spent: " << time_spent << " ms";
    return 0;
}
