class Solution {
public:
    string toHex(int num) {
        if(num == 0){
            return "0";
        }

        string hexChars = "0123456789abcdef";
        string result = "";
        unsigned int n = num;
        while(n > 0){
            result = hexChars[n % 16] + result;
            n /= 16;
        }
        return result;
    }
};
