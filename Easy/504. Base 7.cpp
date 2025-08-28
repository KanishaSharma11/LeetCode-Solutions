class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }

        bool isNegative = num < 0;
        num =abs(num);
        string ans = "";

        while(num > 0){
            int rem = num % 7;
            ans = to_string(rem) + ans;
            num /= 7;
        }

        if(isNegative){
            ans = "-" + ans;
        }

        return ans;
    }
};
