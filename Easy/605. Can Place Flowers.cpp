class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        for(int i = 0; i < len && n > 0; i++){
            if(flowerbed[i] == 0){
                bool emptyPrev = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyNext = (i == (len - 1)) || (flowerbed[i + 1] == 0);
                if(emptyPrev && emptyNext){
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n <= 0;
    }
};
