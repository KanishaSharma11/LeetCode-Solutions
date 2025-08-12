class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        int length = columnTitle.length();

        for(int i = 0; i < length; i++){
            int val = columnTitle[i] - 'A' + 1;
            result = result * 26 + val;
        }
        return result;
    }
};
