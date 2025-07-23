class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i];

            if(curr == first || curr == second || curr == third){
                continue;
            }
            if (curr > first) {
                third = second;
                second = first;
                first = curr;
            } else if (curr > second) {
                third = second;
                second = curr;
            } else if (curr > third) {
                third = curr;
            }
        }
        return (third != LONG_MIN) ? third : first;
    }
};
