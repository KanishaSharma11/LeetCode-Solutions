class Solution{
  public:
    int threeSumClosest(vector<int>& nums, int target){
      sort(nums.begin(), nums.end());
      int closestSum = nums[0] + nums[1] + nums[2];

      for(int i = 0; i < nums.size(); i++){
        int left = i + 1, right = nums.size() - 1;
        while(left < right){
          int currSum = nums[i] + nums[left] + nums[right];

          if(abs(target - currSum) < abs(target - closestSum)){
            closestSum = currSum;
          }
          if(currSum == target){
            returm currSum;
          }
          else if(currSum < target){
            left++;
          }
          else{
            right--;
          }
        }
      }
      return closestSum;
    }
};
