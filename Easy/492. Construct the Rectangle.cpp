class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = (int) sqrt(area);
        while(area % W != 0){
            W--;
        }
        int L = area / W;
        return {L, W};
    }
};
