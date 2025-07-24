class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minSum = nums[0];
        int maxSum = nums[0];
        int currSum = nums[0];
        int minCurrSum = nums[0];

        for(int i = 1; i < nums.size(); i++){
            currSum = max(nums[i], currSum + nums[i]);
            minCurrSum = min(nums[i], minCurrSum + nums[i]);

            if(currSum > maxSum){
                maxSum = currSum;
            }

            if(minCurrSum < minSum){
                minSum = minCurrSum;
            }
        }

        return max(abs(minSum), abs(maxSum));
    }
};
