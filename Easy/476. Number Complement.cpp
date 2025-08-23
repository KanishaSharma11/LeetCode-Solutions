class Solution {
public:
    int findComplement(int num) {
        int bitLength = 0;
        int temp = num;
        while (temp > 0) {
            temp >>= 1;
            bitLength++;
        }
        long long mask = (1LL << bitLength) - 1;
        
        // XOR num with the mask to get the complement
        return num ^ mask;
    }
};
