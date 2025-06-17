class Solution{
  public:
    int lengthOfLongestSubstring(string s){
      int maxLen = 0;
      int n = s.length();

      for(int i = 0; i < n; i++){
        unordered_set<char> seenChar;
        int len = 0;
        for(int j = i; j < n; j++){
          if(seenChar.find(s[j)) == seenChar.end()){
            seenChar.insert(s[j));
            len++;
          }
          else{
            break;
          }
        }
        maxLen = std::max(maxLen, len);
      }
      return maxLen;
    }
};
