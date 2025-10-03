class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> res(len1 + len2, 0);

        for(int i = len1 - 1; i >= 0; i--){
            for(int j = len2 - 1; j >= 0; j--){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int k = (len1 - 1 - i) + (len2 - 1 - j);
                res[k] += mul;
            }
        }

        int carry = 0;
        for(int i = 0; i < len1 + len2; i++){
            int temp = res[i] + carry;
            res[i] = temp % 10;
            carry = temp / 10;
        }

        string s;
        for (int i = len1 + len2 - 1; i >= 0; i--) {
            s += '0' + res[i];
        }
        
        size_t start = s.find_first_not_of('0');
        if (start == string::npos) {
            return "0";
        }
        return s.substr(start);
    }
};
