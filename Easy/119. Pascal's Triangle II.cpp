class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        long long value = 1;
        row.push_back(value);

        for(int k = 1; k <= rowIndex; k++){
            value = value * (rowIndex - k + 1) / k;
            row.push_back((int) value);
        }
        return row;
    }
};
