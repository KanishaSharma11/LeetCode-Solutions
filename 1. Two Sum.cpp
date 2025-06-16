class Solution{
  public:
    vector<int> twoSum(vector<int>& nums, int target){
      vector<int> list;
      for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
          if(nums[i] + nums[j] == target){
            list.push_back(i);
            list.push_back(j);
          }
        }
      }
      return list;
    }
};
