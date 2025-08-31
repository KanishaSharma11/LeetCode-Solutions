class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> sortedScore(score);
        sort(sortedScore.begin(), sortedScore.end(), greater<int>());
        unordered_map<int, int> rankMap;
        for(int i = 0; i < n; i++){
            rankMap[sortedScore[i]] = i + 1;
        }

        vector<string> result(n);
        for(int i = 0; i < n; i++){
            int rank = rankMap[score[i]];
            if (rank == 1) {
                result[i] = "Gold Medal";
            } else if (rank == 2) {
                result[i] = "Silver Medal";
            } else if (rank == 3) {
                result[i] = "Bronze Medal";
            } else {
                result[i] = to_string(rank);
            }
        }
        
        return result;
    }
};
