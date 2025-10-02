class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9);
        vector<set<char>> col(9);
        vector<set<char>> boxes(9);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                if(c == '.'){
                    continue;
                }

                int box = (i / 3) * 3 + (j / 3);

                if(rows[i].count(c) || col[j].count(c) || boxes[box].count(c)){
                    return false;
                }

                rows[i].insert(c);
                col[j].insert(c);
                boxes[box].insert(c);
            }
        }
        return true;
    }
};
