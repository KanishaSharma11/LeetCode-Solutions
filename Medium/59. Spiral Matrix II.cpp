class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m = n * n;
        int i = 1;
        int rowS = 0, rowE = n - 1;
        int colS = 0, colE = n - 1;
        vector<vector<int>> ans(n, vector<int>(n));
        while(rowS <= rowE && colS <= colE && i <= m){
            for(int j = colS; j <= colE; j++){//first row
                ans[rowS][j] = i++;
            }
            rowS++;

            for(int j = rowS; j <= rowE; j++){
                ans[j][colE] = i++;
            }
            colE--;

            for(int j = colE; j >= colS; j--){
                ans[rowE][j] = i++;
            }
            rowE--;

            for(int j = rowE; j >= rowS; j--){
                ans[j][colS] = i++;
            }
            colS++;
        }
        return ans;
    }

};
