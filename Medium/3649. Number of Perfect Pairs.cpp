class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        vector<int> x = nums;

        int n = nums.size();
        vector<long long> absVals(n);

        for(int i = 0; i < n; i++){
            absVals[i] = abs(nums[i]);
        }

        sort(absVals.begin(), absVals.end());
        long long ans = 0;

        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < n && absVals[j] <= 2 * absVals[i]){
                j++;
            }
            ans += (j - i - 1);
        }

        return ans;
    }
};
