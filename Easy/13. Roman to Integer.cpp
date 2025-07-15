class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int prevNum = 0;

        for(char c: s){
            int currentNum = romanMap[c];

            if(prevNum < currentNum){
                total += currentNum - 2 * prevNum;
            }
            else{
                total+=currentNum;
            }

            prevNum = currentNum;
        }
        return total;
    }
};
