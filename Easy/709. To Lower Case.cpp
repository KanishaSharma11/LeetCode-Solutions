class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                ans.push_back(s[i] + 32);
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
