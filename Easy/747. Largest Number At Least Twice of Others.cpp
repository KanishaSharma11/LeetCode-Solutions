class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            map[nums[i]] = i;
        }

        int large = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] > large){
                large = nums[i];
            }
        }

        bool isLarge = false;
        for(int i = 0; i <= (n -  1); i++){
            if(nums[i] != large){
                if(large < (nums[i] * 2)){
                    isLarge = true;
                }
            }
        }

        if(isLarge){
            return -1;
        }

        return map[large];
    }
};
