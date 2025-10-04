class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return {};
        }
        
        int n = matrix[0].size();
        if (n == 0) {
            return {};
        }
        
        vector<int> res;
        int rs = 0, re = m - 1, cs = 0, ce = n - 1;
        
        while (rs <= re && cs <= ce) {
            for (int j = cs; j <= ce; ++j) {
                if (rs >= 0 && rs < m && j >= 0 && j < n) {
                    res.push_back(matrix[rs][j]);
                }
            }
            ++rs;
            
            for (int i = rs; i <= re; ++i) {
                if (i >= 0 && i < m && ce >= 0 && ce < n) {
                    res.push_back(matrix[i][ce]);
                }
            }
            --ce;
            
            if (rs <= re) {
                for (int j = ce; j >= cs; --j) {
                    if (re >= 0 && re < m && j >= 0 && j < n) {
                        res.push_back(matrix[re][j]);
                    }
                }
                --re;
            }
            
            if (cs <= ce) {
                for (int i = re; i >= rs; --i) {
                    if (i >= 0 && i < m && cs >= 0 && cs < n) {
                        res.push_back(matrix[i][cs]);
                    }
                }
                ++cs;
            }
        }
        return res;
    }
};
