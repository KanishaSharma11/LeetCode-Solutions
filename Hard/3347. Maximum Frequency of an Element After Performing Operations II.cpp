#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        if (n == 0) return 0;

        // frequency of original values (already(x))
        unordered_map<long long,int> freq;
        freq.reserve(n * 2);
        for (int v : nums) freq[v]++;

        // build inclusive interval events: +1 at L, -1 at R+1
        map<long long, long long> events;
        for (int v : nums) {
            long long L = (long long)v - k;
            long long R = (long long)v + k;
            events[L] += 1;
            events[R + 1] -= 1;
            // ensure original value is present as a key so we evaluate already(v)
            if (!events.count(v)) events[v] += 0;
        }

        long long curr = 0;
        int ans = 1;
        for (auto &p : events) {
            long long x = p.first;
            curr += p.second;                // curr == eligible(x)
            int eligible = (int)curr;
            int already = 0;
            auto it = freq.find(x);
            if (it != freq.end()) already = it->second;
            int reachable = min(eligible, already + numOperations);
            ans = max(ans, reachable);
        }
        return ans;
    }
};
