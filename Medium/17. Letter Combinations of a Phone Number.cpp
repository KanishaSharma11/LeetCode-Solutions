class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> phoneMap = {
            "",     "",     "abc",  "def",  "ghi",  // 0-4
            "jkl",  "mno",  "pqrs", "tuv",  "wxyz" // 5-9
        };

        vector<string> result;
        string current;

        function<void(int)> backtrack = [&](int index) {
            if(index == digits.size()){
                result.push_back(current);
                return;
            }

            string letters = phoneMap[digits[index] - '0'];
            for (char c : letters) {
                current.push_back(c);
                backtrack(index + 1);
                current.pop_back();
            }
        };

        backtrack(0);
        return result;
    }
};
