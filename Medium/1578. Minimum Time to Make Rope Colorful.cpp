class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int total = 0;
        int i = 0;
        while(i < n){
            int j = i;
            long long sum = 0;
            long long maxv = 0;
            while(j < n && colors[j] == colors[i]){
                sum += neededTime[j];
                if(neededTime[j] > maxv){
                    maxv = neededTime[j];
                }
                j++;
            }
            if(j - i > 1){
                total += sum - maxv;
            }
            i = j;
        }
        return total;
    }
};
