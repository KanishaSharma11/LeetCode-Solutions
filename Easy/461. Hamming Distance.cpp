class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorResult = x ^ y;

        int dist = 0;
        while(xorResult > 0){
            dist += (xorResult & 1);
            xorResult >>= 1;
        }
        return dist;
    }
};
