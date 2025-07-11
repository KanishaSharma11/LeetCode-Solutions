class Solution{
  public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
      vector<vector<int>> result;
      sort(nums.begin(), nums.end());

      for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i - 1]){
          for(int j = i + 1; j < nums.size(); j++){
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;
            int left = j + 1, right = nums.size() - 1;
            while(left < right){
              long long currSum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

              if(currSum > target){
                result.push_back({nums[i], nums[j], nums[left], nums[right]});
                while(left < right && nums[left] == nums[left + 1]) left++;
                while(left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
              }
              else if(currSum < target){
                left++;
              }
              else{
                right--;
              }
            }
          }
        }
      }
      return result;
    }
};
