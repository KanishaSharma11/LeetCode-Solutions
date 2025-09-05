class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string result;
        int i = 0;
        while (i < n) {
            int start = i;
            int count = 0;
            while (i < n && s[i] != ' ') {
                i++;
                count++;
            }
            for (int j = start + count - 1; j >= start; j--) {
                result.push_back(s[j]);
            }
            if (i < n) {
                result.push_back(' ');
                i++;
            }
        }
        return result;
    }
};
