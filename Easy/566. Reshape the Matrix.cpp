class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        if(n == 0){
            return mat;
        }
        int m = mat[0].size();
        if(m == 0){
            return mat;
        }
        
        if(m * n != r * c){
            return mat;
        }

        vector<vector<int>> reshaped(r, vector<int>(c));

        for(int i = 0; i < m * n; i++){
            reshaped[i / c][i % c] = mat[i / m][i % m];
        }

        return reshaped;
    }
};
