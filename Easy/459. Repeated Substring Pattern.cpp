class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        if(n < 2){
            return false;
        }

        std::string doubled = s + s;

        return doubled.substr(1, 2 * n - 2).find(s) != std::string::npos;

    }
};
