class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int currentSum = 0;
        for(int i = 0; i < k; i++){
            currentSum += nums[i];
        }

        int maxSum = currentSum;
        for(int i = k; i < nums.size(); i++){
            currentSum += nums[i] - nums[i - k];
            if(currentSum > maxSum){
                maxSum = currentSum;
            }
        }

        return (double)maxSum / k;
    }
};
