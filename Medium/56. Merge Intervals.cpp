class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            vector<int>& last = result.back();
            if(intervals[i][0] <= last[1]){
                last[1] = max(intervals[i][1], last[1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
