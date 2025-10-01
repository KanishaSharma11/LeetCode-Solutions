class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, subset, ans);
        return ans;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& ans){
        ans.push_back(subset);
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i - 1]){
                continue;
            }
            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset, ans);
            subset.pop_back();
        }
    }
};
