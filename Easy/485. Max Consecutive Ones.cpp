class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcount = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count += 1;
            }
            else if(nums[i] == 0){
                maxcount = max(count, maxcount);
                count = 0;
            }
        }
        maxcount = max(count, maxcount);
        return maxcount;
    }
};
