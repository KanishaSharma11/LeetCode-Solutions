class Solution {
public:
    vector<int> grayCode(int n) {
        int total = 1 << n;
        vector<int> res;
        for(int i = 0; i < total; i++){
            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};
