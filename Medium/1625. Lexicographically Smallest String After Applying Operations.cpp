class Solution {
public:
    string addOperation(string s, int a){
        for(int i = 1; i < s.size(); i+=2){
            s[i] = ((s[i] - '0' + a) % 10) + '0';
        }
        return s;
    }

    string rotateOperation(string s, int b){
        int n = s.size();
        return s.substr(n - b) + s.substr(0, n - b);
    }

    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> visited;
        string smallest = s;

        q.push(s);
        visited.insert(s);
        while(!q.empty()){
            string curr = q.front();
            q.pop();

            smallest = min(smallest, curr);

            string added = addOperation(curr, a);
            if(!visited.count(added)){
                visited.insert(added);
                q.push(added);
            }

            string rotated =  rotateOperation(curr, b);
            if(!visited.count(rotated)){
                visited.insert(rotated);
                q.push(rotated);
            }
        }

        return smallest;
    }
};
