class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minCount = INT_MAX;
        int left = 0;
        int sum = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];

            while(sum >= target){
                minCount = min(minCount, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return minCount == INT_MAX ? 0 : minCount;

        return minCount == INT_MAX ? 0 : minCount;
    }
};
