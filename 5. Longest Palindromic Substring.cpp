class Solution{
  public:
    bool check(string& s, int low, int high){
      while(low < high){
        if(s[low] != s[high]){
          return false;
        }

        low++;
        high--;
      }

      return true;
    }

    string longestPalindrome(string s){
      int n = s.size();
      int maxLen = 1, start = 0;

      for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
          if(check(s, i, j) && (j - 1 + 1) > maxLen){
            start = i;
            maxLen = (j - i + 1);
          }
        }
      }

      return s.substr(start, maxLen);
    }
};
