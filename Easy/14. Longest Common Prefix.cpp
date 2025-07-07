class Solution{
  public:
    string longestCommonPrefix(vector<string>& strs){
      if(strs.empty()){
        return "";
      }

      string prefix = strs[0];

      for(int i = 1; i < strs.size(); i++){
        while(sts[i].find(prefix) != 0){
          prefix.pop_back();
          if(prefix.empty()){
            retturn "";
          } 
        }
      }
      return prefix;
    }
};
