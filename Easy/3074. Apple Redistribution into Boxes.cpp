class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;
        for(int i = 0; i < apple.size(); i++){
            totalApples += apple[i];
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        int sum = 0;
        int count = 0;

        for(int cap: capacity){
            sum += cap;
            count++;
            if(sum >= totalApples){
                return count;
            }
        }
        return count;
    }
};
