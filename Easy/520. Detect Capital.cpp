class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        bool allUpper = true;
        for(int i = 0; i < n; i++){
            if(!isupper(word[i])){
                allUpper = false;
                break;
            }
        }

        if(allUpper){
            return true;
        }

        bool allLower = true;
        for(int i = 0; i < n; i++){
            if(!islower(word[i])){
                allLower = false;
                break;
            }
        }
        if(allLower){
            return true;
        }

        if(isupper(word[0])){
            for(int i = 1; i < n; i++){
                if(!islower(word[i])){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};
