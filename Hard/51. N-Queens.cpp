class Solution {
public:
    void solve(int n, int row, vector<int>& col, vector<vector<string>>& ans){
        if(row == n){
            vector<string> board(n, string(n, '.'));
            for(int i  = 0; i < n; i++){
                board[i][col[i]] = 'Q';
            }
            ans.push_back(board);
            return;
        }
        for(int j = 0; j < n; j++){
            bool safe = true;
            for(int k = 0; k < row; k++){
                if(col[k] == j || abs(col[k] - j) == abs(k - row)){
                    safe = false;
                    break;
                }
            }

            if(safe){
                col[row] = j;
                solve(n, row + 1, col, ans);
                col[row] = -1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n, -1);
        vector<vector<string>> ans;
        solve(n, 0, col, ans);
        return ans;
    }
};
