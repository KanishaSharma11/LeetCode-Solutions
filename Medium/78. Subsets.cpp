#include<vector>
class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& current, int start, vector<vector<int>>& result){
        result.push_back(current);

        for(int i = start; i < nums.size(); i++){
            current.push_back(nums[i]);
            backtrack(nums, current, i + 1, result);
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, current, 0, result);
        return result;
    }
};
