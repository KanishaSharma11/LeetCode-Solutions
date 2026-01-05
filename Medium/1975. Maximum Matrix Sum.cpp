class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total = 0;
        int negCount = 0;
        long long minAbs = LLONG_MAX;

        for (auto &row : matrix) {
            for (int x : row) {
                if (x < 0) negCount++;
                long long absVal = llabs(x);
                total += absVal;
                minAbs = min(minAbs, absVal);
            }
        }

        if (negCount % 2 == 0)
            return total;
        else
            return total - 2 * minAbs;
    }
};
