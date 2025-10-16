class Solution {
public:
    string reverseWords(string s) {
        int write = 0;
        bool last_space = true;
        for(int read = 0; read < s.size(); read++){
            if(s[read] != ' '){
                s[write++] = s[read];
                last_space = false;
            }               
             
            else {
                if (!last_space) {
                    s[write++] = ' ';
                    last_space = true;
                }
            }
        }
        if(write > 0 && s[write - 1] == ' ') {
            --write;
        }
        s.resize(write);
        // Reverse the entire string
        std::reverse(s.begin(), s.end());
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                ++i;
                continue;
            }
            int start = i;
            while(i < s.size() && s[i] != ' ') {
                ++i;
            }
            int end = i - 1;
            std::reverse(s.begin() + start, s.begin() + end + 1);
        }
        return s;   
    }
};
