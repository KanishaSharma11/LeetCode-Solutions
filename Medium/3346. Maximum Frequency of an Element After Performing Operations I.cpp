class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        const int MAX_VAL = 100000;
        vector<int> freq(MAX_VAL + 1, 0);
        for (int num : nums) {
            if (num >= 1 && num <= MAX_VAL) {
                freq[num]++;
            }
        }
        vector<long long> prefix(MAX_VAL + 2, 0);
        for (int i = 1; i <= MAX_VAL; ++i) {
            prefix[i] = prefix[i - 1] + freq[i];
        }
        long long ans = 0;
        for (int x = 1; x <= MAX_VAL; ++x) {
            int left = max(1, x - k);
            int right = min(MAX_VAL, x + k);
            long long total_in_range = prefix[right] - prefix[left - 1];
            long long base = freq[x];
            long long candidates = total_in_range - base;
            long long max_for_x = base + min(candidates, (long long)numOperations);
            ans = max(ans, max_for_x);
        }
        // Also consider the maximum frequency without operations
        for (int i = 1; i <= MAX_VAL; ++i) {
            ans = max(ans, (long long)freq[i]);
        }
        return ans;
    }
};
