class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int count = 1;
        int n = nums.size() / 3;
        
        if(nums.size() == 1){
            result.push_back(nums[0]);
            return result;
        }

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]){
                count++;
            }

            else{
                if(count > n){
                    result.push_back(nums[i - 1]);
                }
                count = 1;
            }

            if(i == nums.size() - 1 && count > n){
                result.push_back(nums[i]);
            }
        }

        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
