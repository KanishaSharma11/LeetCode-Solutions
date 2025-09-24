class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0;
        int countL = 0;
        int n = s.length();

        for(int i = 0; i < n; i++){
            if(s[i] == 'A'){
                countA++;
                countL = 0;
            }
            else if(s[i] == 'L'){
                countL++;

                if(countL >= 3){
                    return false;
                }
            }
            else{
                countL = 0;
            }
        }
        return countA < 2;
    }
};
